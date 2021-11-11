#include<iostream>
using namespace std;

int main()
{
    int start,duration;

    cin>>start>>duration;
    switch(duration>=0)
    {
        case 1:
        while(duration>=60)
        {
            start+=100;
            duration-=60;
        }
        start+=duration;
        start=(start%100>=60)?start+40:start;
        break;
        
        default:
        while(duration<=-60)
        {
            start-=100;
            duration+=60;
        }
        if(start%100+duration>=0)
        start+=duration;
        else start=start+duration-40;

        break;
    }
    if(!(start/100))
    {
        char* end=new char[3];
        end[0]='0';
        end[1]=start/10+'0';
        end[2]=start%10+'0';
        for(int i=0;i<3;i++) cout<<end[i];
        return 0;
    }
    cout<<start;
    return 0;
    
}