#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m=n%10;
    n/=10;
    while(n)
    {
        m=m*10+n%10;
        n/=10;
    }
    cout<<m;
}