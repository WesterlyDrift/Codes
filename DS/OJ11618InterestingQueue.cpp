#include<iostream>
#include<algorithm>

using namespace std;

/*class queue
{
    private:
    struct node
    {
        int data;
        node* next;
        ~node(){};
        node():next(NULL){};
        node(const int& x,node* n=NULL)
        {
            data=x;
            next=n;
        }
    };
   

    public:
    queue();
    ~queue();
    void enQueue(const int& x);
    void deQueue();
    int gethead() const;
    int getrear() const;
    node *front,*rear;
};
*/
int findmax(int a[],int i,const int k)
{
    int tmax=a[i];
    for(int j=i;j>i-k;j--)
    {
        if(a[j]>tmax) tmax=a[j];
    }
    return tmax;
}
int findmin(int a[],int i,const int k)
{
    int tmin=a[i];
    for(int j=i;j>i-k;j--)
    {
        if(a[j]<tmin) tmin=a[j];
    }
    return tmin;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int* a=new int[n];
    for(int i=0;i<n;++i)
    cin>>a[i];
    int min[n-k+1]={0};
    int max[n-k+1]={0};
    int t1=a[0];
    int t2=a[0];
    
    for(int i=0;i<k;i++)
    {
        
        if(a[i]>t1) t1=a[i];
        if(a[i]<t2) t2=a[i];
    }

    max[0]=t1;
    min[0]=t2;
    for(int j=k;j<n;j++)
    {   if(t1==a[j-k])  t1=findmax(a,j,k);
        else if(a[j]>t1) t1=a[j];
        
        if(t2==a[j-k]) t2=findmin(a,j,k);
        else if(a[j]<t2) t2=a[j];

        max[j-k+1]=t1;
        min[j-k+1]=t2;
    }
    cout<<min[0];
    for(int x=1;x<n-k+1;x++)
    cout<<' '<<min[x];
    cout<<endl<<max[0];
    for(int y=1;y<n-k+1;y++)
    cout<<' '<<max[y];
    return 0;

}

/*queue::queue()
{
    front=rear=NULL;

}

queue::~queue()
{   
    node* tmp;
    while(front)
    {
        tmp=front;
        front=front->next;
        delete tmp;
    }
    rear=NULL;
}

void queue::enQueue(const int& x)
{
    if(rear==NULL)
    front=rear=new node(x);
    else
    rear=rear->next=new node(x);
    return ;
}

void queue::deQueue()
{
    cout<<front->data;
    node* tmp=front;
    front=front->next;
    if(!front) rear=NULL;
    delete tmp;
}

int queue::gethead() const
{
    return front->data;
}

int queue::getrear() const
{
    return rear->data;
}

*/