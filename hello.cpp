#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int* p;
    srand(time(NULL));
    p=(int*)malloc(10*sizeof(int));
    for(int i=0;i<10;++i)
    p[i]=rand()%10;
    //free(p);
    for(int j=0;j<10;j++)
    printf("%d ",p[j]);
    return 0;

}
//just for test