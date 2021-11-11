#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int m;
int n;
int tmp;
int main()
{   

    cin>>m;
    int m1=m;
    bool* flag=new bool[m]{false};
    while(m1-->0)
    {
        cin>>n;
        stack<int> s;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int current=0;
        for(int j=1;j<=n;j++)
        {
            s.push(j);
            while(!s.empty()&&s.top()==v[current])
            {
                s.pop();
                current++;
            }
        }
        flag[m-m1-1]=(current!=n);
        
       
    }
    cout<<(flag[0]?"No":"Yes");
    for(int y=1;y<m;y++)
    cout<<endl<<(flag[y]?"No":"Yes");
    return 0;
}