#include<stdio.h>
#include<stdlib.h>
#include<list>

typedef int T;
typedef struct node* ptrnode;
struct node
{
    T data;
    ptrnode next;
    node(const int& x,list n=NULL):data(x),next(n){};
    
};
typedef ptrnode list;
list read(); //details omitted here.
void print(list l);//output NULL for empty list
list merge(list l1,list l2);

int main()
{
    list l1,l2;
    l1=read();
    l2=read();
    list l=merge(l1,l2);
    print(l);
    print(l1);
    print(l2);

    return 0;
}

list read()
{
    printf("Starting read inputs:\n");
    int n;
    scanf("%d",&n);
    list s=(list)malloc(sizeof(struct node));
    s->next=NULL;
    list t=s;
    for(int i=0;i<n;i++)
    {
        list p=(list)malloc(sizeof(struct node));
        scanf("%d",&(p->data));
        t=t->next=p;
        
    }
    t->next=NULL;
    printf("End of reading inputs.\n");
    return s;
}

void print(list l)
{
    if(l==nullptr) 
        printf("NULL");
    else
    {
        while(l)
        {
            printf("%d ",l->data);
            l=l->next;
        }
    }
    return ;
}

list merge(list l1,list l2)
{   
    list l,pa,pb,pc;
    l=(list)malloc(sizeof(struct node));
    pa=l1->next;
    pb=l2->next;
    pc=l;

    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc=pc->next=pa;
            pa=pa->next;
        }
        else 
        {
            pc=pc->next=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    l1->next=NULL;
    l2->next=NULL;
    return l;

}