#include<iostream>
using namespace std;
class queue
{   
    private:
    int* elem;
    int current;
    

    public:
    int front,rear;
    void enQueue(const int& x);
    void deQueue();
    int getHead() const;
    int maxlen;
    queue(const int& x);
    void doublespace();
    ~queue();
};
 int main()
 {
     int s,n,op,x;
     cin>>s>>n;
     queue q(s);
     while(n-->0)
     {
         cin>>op;
         cout<<endl;
         if(!op)
         {  
            cin>>x;
            q.enQueue(x);
         }
         else 
         {
            q.deQueue();
         }
     }
     return 0;
 }

 queue::queue(const int& x)
 {
    maxlen=x;
    elem=new int[maxlen];
    front=rear=current=0; 
    return ;
 }

queue::~queue()
{
    delete [] elem;
    return ;
}
void queue::enQueue(const int& x)
{
    if((rear+1)%maxlen==front)
    doublespace();
    rear=(rear+1)%maxlen;
    elem[rear]=x;
    current++;
    cout<<rear<<' '<<current;
    return ;
}

void queue::doublespace()
{
    int* tmp=elem;
    elem=new int[maxlen*2];
    
    for(int i=0;i<maxlen;++i)
    {
        elem[i]=tmp[(front+i)%maxlen];
    }
    front=0;
    rear=maxlen-1;
    maxlen*=2;
    delete [] tmp;
    return ;
}

int queue::getHead() const
{
    return elem[front];
}
void queue::deQueue()
{   if(front==rear)
    {
        cout<<front<<' '<<'0';
        return ;
    }
    else
    {
    front=(front+1)%maxlen;
    current--;
    cout<<front<<' '<<current;
    return ;
    }
}

