#include<stdio.h>
#include<stdlib.h>

typedef struct Node* PtrToNode;
struct Node
{
    int data;
    PtrToNode next;
};
typedef PtrToNode list;
int factorialSum(list L);

int main()
{
    int n,i;
    list l,p;

    scanf("%d",&n);
    l=NULL;
    for(i=0;i<n;i++)
    {
        p=(list)malloc(sizeof(struct Node));
        scanf("%d",&p->data);
        p->next=l;
        l=p;
    }
    printf("%d\n",factorialSum(l));
    return 0;
}

int factorialSum(list l)
{   
    int res=0;
    int tmp=0;
    for(list t=l;t;t=t->next)
    {
        tmp=t->data;
        if(!tmp) { res++; continue;}
        for(int i=tmp-1;i>0;i--)
        tmp*=i;
        res+=tmp;
    }
    return res;
}
