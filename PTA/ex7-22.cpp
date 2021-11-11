#include<iostream>
using namespace std;

int main()
{
    int minute;
    bool cases;
    cin>>minute;
    const int turtle=minute*3;
    int relative=0;
    while(minute>0)
    {
        switch(relative<=0)
        {
            case 1:
                relative+=60;
                cases=1;  
                break;
            default:
                relative-=90;
                minute-=20;
                cases=0;
                break;

        }
        minute-=10;
    }
    switch(cases)
    {
        case 1:
            relative+=6*minute;
            break;
        default:
            relative-=3*minute;
            break;
    }
    if(relative>0)
    cout<<"^_^ "<<relative+turtle;
    else if(relative<0)
    cout<<"@_@ "<<turtle;
    else cout<<"-_- "<<turtle;
    return 0;
}