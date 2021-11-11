#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n;
    
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];  
    }
    if(n==1) { cout<<a[0]; return 0;}
    sort(a,a+n);
    int res=a[0]+a[1],counter=2;
    int tmp=res;
    while(counter<n)
    {
        if(counter>=n-1)
        {
            res+=a[n-1]+tmp;
            break;
        }
        else if(tmp<=a[counter+1])
        {   
            tmp+=a[counter++];
            res+=tmp;
            
        }
        else 
        {
            tmp+=a[counter]+a[counter+1];
            res+=tmp+a[counter]+a[counter+1];
            counter+=2;
        }
    }
    cout<<res;
    return 0;
}



/*
int main()
{
    int n;
    int cost=0;
    int tmp;
    cin>>n;
    priority_queue<int> q;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        q.push(tmp);
    }
    for(int i=1;i<n;i++)
    {
        int a1,a2;
        a1=q.top();
        q.pop();
        a2=q.top();
        q.pop();
        a1+=a2;
        cost+=a1;
        q.push(a1);
    }
    cout<<cost;
    return 0;
}

*/