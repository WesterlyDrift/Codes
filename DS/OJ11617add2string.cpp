#include<iostream>
#include<cstring>
using namespace std;
#define maxnum 600
char* add_two_string(char*,char*);
int count=0;
int main()
{
    int m,n;
    cin>>m>>n;
    char* str1=new char[m];
    char* str2=new char[n];
    cin>>str1>>str2;
    cout<<add_two_string(str1,str2);
    return 0;
}
/*char* add_two_string(char* p,char* q)

{   
    int maxlen=max(strlen(p),strlen(q));
    char* res=new char[maxlen];
    int carry=0;
    int tmp;
    int x,y;
    int p1=0,p2=0;
    while(p1<strlen(p)||p2<strlen(q)||carry)
    {   if(count==maxlen)
        {
            char* l=res;
            res=new char[maxlen+1];
            res=l;
            res[maxlen]='1';
            delete [] l;
            return res;
        }   
        
        if(p1<strlen(p)) {x=p[p1]-'0';p1++;}
            else x=0;
        if(p2<strlen(q)) {y=q[p2]-'0';p2++;}
            else y=0;
        tmp=x+y+carry;
        res[count++]=tmp%10+'0';
        carry=tmp/10;
    }
    return res;
}


*/
char* add_two_string(char* p,char* q)
{   int pl=strlen(p),ql=strlen(q);
    int carry=0,tmp=0;
    int maxlen=max(pl,ql);
    char* res=new char[maxlen]{'0'};
    int* mag=new int[maxlen]{0};
    for (int i=0;i<maxlen;i++)
    {
        if(i<pl&&i<ql)
        mag[i]=p[i]-'0'+q[i]-'0';
        else if(i>=pl)
        mag[i]=q[i]-'0';
        else if(i>=ql)
        mag[i]=p[i]-'0';
    }
    for(int j=0;j<maxlen;j++)
    {   
        tmp=mag[j]+carry;
        res[j]=tmp%10+'0';
        carry=tmp>=10?1:0;
    }
    if(carry)
    {
        char* l=res;
        res=new char[maxlen+1];
        res[maxlen]='1';
        for(int i=0;i<maxlen;i++)
            res[i]=l[i];
        delete [] l;
    }
    return res;
}
//Accepted.