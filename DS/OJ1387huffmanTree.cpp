#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    long long tmp;
    cin>>n;
    vector<long long> a;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        a.push_back(tmp);   
    }
    if(n==1) { cout<<'0'; return 0;}
    sort(a.begin(),a.end());
    long long res=0;
    bool added=false;
    while(a.size()>1)
    {   
        added=false;
        tmp=a[1]+a[0];
        res+=tmp;
        a.erase(a.begin(),a.begin()+2);
        for(int k=0;k<a.size();k++)
        {if(tmp<=a[k]) 
            {   a.insert(a.begin()+k,tmp);
                added=true;
                break;
            }
        }
        if(!added) a.push_back(tmp);
       
    
    }

    cout<<res;
    

    /*
    int res=a[0]+a[1],counter=2;
    int tmp=res;
    while(counter<n)
    {
        if(counter>=n-1)
        {
            tmp+=a[n-1];
            res+=tmp;
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

    */
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