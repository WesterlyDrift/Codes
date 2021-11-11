#include<stdio.h>
#include<math.h>

int IsTheNumber (const int N);

int main()
{
    int n1,n2,i,cnt;
    scanf("%d %d",&n1,&n2);
    cnt=0;
    for(i=n1;i<=n2;i++)
    {
        if(IsTheNumber(i))
        cnt++;
    }
    printf("cnt=%d\n",cnt);
    return 0;
}
int IsTheNumber(const int n)
{   int tmp=n;
    if (abs((double)sqrt(n)-(int)sqrt(n))>1e-4) return 0;
    int a[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    for(;tmp>0;tmp/=10)
    {
        int mod=tmp%10;
        if(a[mod]!=-1) return 1;
        a[mod]=mod;
    }
    return 0;
}