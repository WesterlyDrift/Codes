#include<stdio.h>
int main()
{
    int a,n;
    scanf("%d %d",&a,&n);
    if(!n) { printf("0");  return 0;}
    int* arr=new int[n*2]{0};
    for(int i=0;i<n;i++)
    {
        arr[i]=a*(n-i);    
    }
    int current;
    int j,mag;
    for(j=0;j<n||arr[j]>0;j++)
    {   
        current=j;
        mag=arr[j]%10;
        while(arr[j]>=10)
        {
            arr[j]/=10;
            arr[++current]+=arr[j]%10;
        }
        arr[j]=mag;
    }
    for(int k=j-1;k>=0;k--)
        printf("%d",arr[k]);
    return 0;
}