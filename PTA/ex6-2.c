#include<stdio.h>

#define maxn 10

double f(int n,double a[],double x);

int main()
{
    int n,i;
    double a[maxn],x;
    scanf("%d %lf",&n,&x);
    for(int i=0;i<=n;i++)
    {
        scanf("%lf",&a[i]);
        printf("%.1f\n",f(n,a,x));
        return 0;
    }

}
double f(int n,double a[],double x)
{   double tmp=a[n];
    for(int i=n;i>0;i--)
    {
        tmp=tmp*x+a[i-1];
    }
    return tmp;
}