#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    clock_t start,stop;
    // clock_t is the type of return value of clock()
    double duration;
    //measured in seconds
    start=clock();
    //MyFunction();
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK;
    return 0;
}

//CLK_TCK is 1000 on this machine.