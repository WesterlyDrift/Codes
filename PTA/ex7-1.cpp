#include<iostream>
using namespace std;

int main()
{
    int cm;
    cin>>cm;
    int foot;
    int inch;
    int inches;
    inches=cm/2.54;
    inch=inches%12;
    foot=inches/12;
    cout<<foot<<' '<<inch;
    return 0;
}