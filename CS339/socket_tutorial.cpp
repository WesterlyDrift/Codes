#include<stdio.h>
#include<winsock2.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
using namespace std;

#ifndef INADDR_NONE
#define INADDR_NONE oxffffffff
#endif  //INADDR_NONE

struct sockaddr_in
{
    u_char sin_len;         //length of address
    u_char sin_family;      //cluster of addresses(TCP/IP: AF_INET)
    u_short sin_port;       //port number
    struct in_addr sin_addr;//IP address
    char sin_zero[8];       //dumb(0)
};
int main()
{
    return 0;
}



//socket API functions


int WSAStartup(WORD wVersionRequested,LPWSADATA lpWSADATA);
//(version of winsock,high for subedition,low for principal edition
//0x102 for version2.1

int WSACleanup(void);
//unbind socket lib, free the sources occupied by socket lib

//create a socket
// sd=socket(protofamily,type,proto);
//(TCP/IP: PF_INET;SOCK_STREAM,SOCK_DGRAM,SOCK_RAW;0 as default)
int closesocket(SOCKET sd);
int bind(SOCKET sd,sockaddr_in localaddr,u_char addrlen);
//Address Wildcard: INADDR_ANY
 int listen(SOCKET sd,int queuesize);
 int connect(SOCKET sd,u_char saddr,u_char saddrlen);
 //SOCKET accept(SOCKET sd,u_char caddr,u_char caddrlen);

/*
htons   host to network byte order (16B)
ntohs
htonl                               32B
ntohl

*/

//inet_addr() 实现点分十进制IP地址32位IP地址转换
//gethostbyname()实现域名到32位IP地址转换
//-返回一个指向结构hostent的指针

struct hostent
{
    char FAR*          h_name;     //official host name
    char FAR* FAR*     h_aliases;  //other aliases
    short              h_addrtype; //address type
    short              h_length;   //address length
    char FAR* FAR*     h_addr_list;//list of address
};
#define h_addr h_addr_list[0]
struct servent
{
    char FAR*       s_name;     //official service name
    char FAR* FAR*  s_aliases;  //other aliases
    short           s_port;     //port for this service
    char FAR*       s_proto;    //protocol to use
};
//getservbyname() 返回一个指向servent的指针

struct protoent
{
    char FAR*       p_name;     //official protocol name
    char FAR* FAR*  p_aliases;  //list of aliases allowed
    short           p_proto;    //official protocol number
};
//getprototype()实现协议名到协议号的转换
//-返回一个指向protoent的指针

/* TCP客户端软件流程
1.确定服务器IP地址与端口号
2.创建套接字
3.分配本地端点地址（IP地址+端口号） 可以被自动实现bind
4.连接服务器（套接字）
5.遵循应用层协议进行通信
6.关闭/释放连接

UDP客户端软件流程
1.确定服务器IP地址与端口号
2.创建套接字
3.分配本地端点地址（IP地址+端口号）
4.指定服务器端点地址，构造UDP数据报（无需建立连接）
5.遵循应用层协议进行通信
6.关闭/释放套接字

*/

//implementation of connectsock()
void errexit(const char*,const char*);
void errexit(const char*,int);
void errexit(const char*,const char*,const char*,int);
SOCKET connectsock(const char* host,const char* service,const char* transport)
{
    struct hostent *phe;//pointer to information entry
    struct servent *pse;//pointer to service information entry
    struct protoent *ppe; //pointer to protocol information entry
    struct sockaddr_in sin; //an internet endpoint address
    int s,type;  //socket descriptor and socket type

    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET; //IPV4

    //map service name to port number
    if(pse=getservbyname(service,transport))
        sin.sin_port=pse->s_port;
    else if((sin.sin_port=htons((u_short)atoi(service)))==0)
        errexit("can't get \"%s\" service entry\n",service);
    
    //map host name to IP address,allowing for dotted decimal
    if(phe=gethostbyname(host))
        memcpy(&sin.sin_addr,phe->h_addr,phe->h_length);
    else if((sin.sin_addr.S_addr=inet_addr(host))==INADDR_NONE)
        errexit("can't get \"%s\" host entry\n",host);

    // map protocol name to protocol number 
    if((ppe=getprotobyname(transport))==0)
        errexit("can't get \"%s\" protocol entry\n",transport);
    // use protocol to choose a socket type
    if(strcmp(transport,"udp")==0)
        type=SOCK_DGRAM;
    else 
        type=SOCK_STREAM;

    //allocate a socket
    s=socket(PF_INET,type,ppe->p_proto);
    if(s==INVALID_SOCKET)
        errexit("can't create socket: %d\n",GetLastError());
    //connect the socket
    if(connect(s,(struct sockaddr*)&sin,sizeof(sin))==SOCKET_ERROR)
        errexit("can't connect to %s.%s: %d\n",host,service,GetLastError());
    return s;
}

/*4种类型基本服务器
1.循环无连接 iterative connectionless
2.循环面向连接 iterative connection-oriented
3.并发无连接 concurrent connectionless
4.并发面向连接 concurrent connection-oriented

-1-
-创建套接字
-绑定端点地址（INADDR_ANY+port number)
-反复接收来自客户端的请求
-遵循应用层协议，构造响应报文，发送给客户，跳回上步

数据发送：sendto()发送数据报
服务器端不能使用connect()函数

获取客户端点地址：调用recvfrom()函数接收数据时，自动提取

-2-
-创建主套接字，并绑定熟知端口号
-设置主套接字为被动监听模式，准备用于服务器
-调用accept()接受下一个连接请求（通过主套接字），
创建新套接字用于与该客户建立连接。
-遵循应用层谢轶，反复接收客户请求，构造并发送响应（用新套接字）
-关闭连接，返回第三步继续调用accept()

-3-
主线程1：创建套接字，绑定熟知端口号
主线程2：反复调用recvfrom()，接收下一个客户的请求，并创建
新线程处理该客户响应
子线程1：接收一个特定请求
子线程2：依据应用层协议构造响应报文，并调用sendto()发送
子线程3：推出（一个子线程处理一个请求后即终止）

-4-
主线程1：创建（主）套接字，绑定熟知端口号
主线程2：设置主套接字为被动监听模式，准备用于服务器
主线程3：反复调用accept()接收下一个连接请求（主套接字），
并创建一个新的子线程处理该客户响应
子线程1：接收一个客户的服务请求（通过新创建的套接字）
子线程2：遵循应用层协议与特定客户进行交互
子线程3：关闭/释放连接并终止线程


*/