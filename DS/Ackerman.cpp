#include<iostream>
using namespace std;
int ackerman1(int m,int n);
int ackerman2(int m,int n);
#define maxsize 200000000
int main()
 {
    int m,n;
    cin>>m>>n;
    cout<<ackerman2(m,n);
    return 0;
 }

 int ackerman1(int m,int n)
 {
    if(m==0)
        return n+1;
    else if(n==0)
    {
        int p=ackerman1(m-1,1);
        return ackerman1(m-1,1);
    }
    else if(n!=0)
    {
        int q=ackerman1(m,n-1);
        return ackerman1(m-1,q);

    }
    return -1;
 }

 //non-recursive version
 int ackerman2(int m,int n)
 {
     struct 
     {
         int vm,vn;//store the value of m and n
         int vf;// store the value of akm(m,n)
         int tag;// tag=akm(m,n)known?0:1
     }st[maxsize];

     int top=-1;//stack pointer
     top++;//init pushed
     st[top].vm=m;
     st[top].vn=n;
     st[top].tag=1;
     
     while(top>-1)

{
    if(st[top].tag==1)//stack-top vf is not calculated
    {

         if(st[top].vm==0) //case 1
         {
             st[top].vf=st[top].vn+1;
             st[top].tag=0;
         }

         else if(st[top].vn==0) //case 2
        {
            top++;
            st[top].vm=st[top-1].vm-1;
            st[top].vn=1;
            st[top].tag=1;
        }

        else  //case 3
        {
            top++;
            st[top].vm=st[top-1].vm;
            st[top].vn=st[top-1].vn-1;
            st[top].tag=1;
        }
    }
    else if(st[top].tag==0)//vf is calculated
    {
        if(top>0&&st[top-1].vn==0) //case 2
        {
            st[top-1].vf=st[top].vf;
            st[top-1].tag=0;
            top--;
        }
    }
    if(top==0&&st[top].tag==0) break;

}
    return st[top].vf;
     
 }