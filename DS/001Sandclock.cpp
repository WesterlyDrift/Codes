#include<stdio.h>
void printSandClock(int n,char c);
int main()
{
    printf("please input the number and shape of the symbols!");
    int n;
    char c;
    scanf("%d %c",&n,&c);
    int level=1;
    for (;level*2*(level+2)+1<n;level++ );
    int left=n-level*2*(level+2)-1;
    printSandClock(level,c);
    printf("%d",left);
}

void printSandClock(int n,char c)
{
    for(int i=1;i<=2*n+1;i++);
        //for(int j=)
};