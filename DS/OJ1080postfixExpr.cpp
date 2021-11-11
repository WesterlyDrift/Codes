#include<iostream>
#include<stack>
using namespace std;

int main()
{   int res=0;
    int op1=0;
    int op2=0;
    int tmp=0;
    stack<char> s;
    stack<int> st;
    char c[10001];
    cin.getline(c,10001,'@');
    for(int i=0;c[i];++i)
    {   
        if(c[i]>='0'&&c[i]<='9')
        tmp=tmp*10+c[i]-'0';
        else 
        {   if(c[i]=='.')
                {   st.push(tmp);
                    tmp=0;
                }
            else 
            {
                op2=st.top();
                st.pop();
                op1=st.top();
                st.pop();
                switch (c[i])
                {
                case '+':
                    tmp=op1+op2;
                    break;
                case '-':
                    tmp=op1-op2;
                    break;
                case '*':
                    tmp=op1*op2;
                    break;
                case '/':
                    tmp=op1/op2;
                    break;
                 
                }
                st.push(tmp);
                tmp=0;    
                }
        }
    }
    cout<<st.top();
    return 0;
}