#include<iostream>
#include<list>
#include<queue>
using namespace std;

int main()
{
    queue<int,list<int>> q1;//the second param can be default
    queue<int,deque<int>> q2;

    int i;

    for(int i=0;i<10;i++) q1.push(i);
    while(!q1.empty())
    {
        cout<<q1.front()<<' ';
        q1.pop();
    }
    cout<<endl;

    for(int j=0;j<10;++j) q2.push(j);
    while(!q2.empty())
    {
        cout<<q2.front()<<' ';
        q2.pop();
    }
    cout<<endl;

    return 0;
}