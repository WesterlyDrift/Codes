#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;


int main()
{   
    string s[2]={"AM","PM"};
    int afternoon=0;
    int hour,minute;
    scanf("%d:%d",&hour,&minute);
    if(hour>12) {hour-=12; afternoon=1;}
    if(hour==12) afternoon=1;
    switch(afternoon)
    {
        case 1:
        printf("%d:%d PM",hour,minute);
        break;
        default:
        printf("%d:%d AM",hour,minute);
        break;

    }
    return 0;
}