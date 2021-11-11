#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    bool negative=true;
    scanf("%d",&n);
    int a[n];
    
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    int max=0,temp=0;
    int start=0,tempstart=0,end=0,pointer=0;
    while(pointer<n)
    {   
        if(a[pointer]>=0)
            negative=false;
        temp+=a[pointer];
        if (temp<0) 
        {temp=0;
         tempstart=1+pointer;
        }
        if(temp>max)
        {
            max=temp;
            start=tempstart;
            end=pointer;
        }
        pointer++;
        
    }
    if (negative)
        {printf("%d %d %d",max,a[0],a[n-1]);
         return 0;
        }
    else if(max==0)
    printf("0 0 0");
    else printf("%d %d %d",max,a[start],a[end]);
    return 0;
}