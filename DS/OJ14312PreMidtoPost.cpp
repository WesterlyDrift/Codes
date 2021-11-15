#include<iostream>
#include<stack>
using namespace std;

void post(int pre[],int mid[],const int root,const int start,const int end);
int main()
{
    int n;
    cin>>n;
    int* a=new int[n];
    int *b=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    post(a,b,0,0,n-1);
    return 0;
}

void post(int pre[],int mid[],const int root,const int start,const int end) 
{
    if(start>end) return ;
    
    int i=start;
    while(i<end&&mid[i]!=pre[root]) {i++; }
    post(pre,mid,root+1,start,i-1);
    post(pre,mid,root+1+i-start,i+1,end);
    cout<<pre[root]<<' ';
}

//accepted.