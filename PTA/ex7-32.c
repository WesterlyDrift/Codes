#include<stdio.h>
#include<string.h>

char* a[500000]={""};
int count=0;
int main()
{
    while(scanf("%s",a[count++]));
    while(count-->0)
    printf("%s ",a[count]);
    return 0;
}