#include<iostream>
using namespace std;
template<class T>
class queue
{
    public:
        virtual bool isEmpty()=0;
        virtual void enQueue(const T& x)=0;
        virtual T deQueue()=0;
        virtual T getHead()=0;
        virtual ~queue(){};
};

template<class T>
class seqQueue:public queue<T>
{
    private:
        T* elem;
        int maxSize;
        int front,rear;

        void doubleSpace();
    public:
        seqQueue(int size=10)
        {
            elem=new T[size];
            maxSize=size;
            front=rear=0;
        }

        ~seqQueue(){delete [] elem;}
        bool isEmpty(){return rear==front;}
        void enQueue(const T& x);
        T deQueue();
        T getHead()
        { return elem[(front+1)%maxSize];}
};

template<class T>
void seqQueue<T>::doubleSpace()
{
    T* tmp=elem;
    elem=new T[maxSize*2];
    for(int i=0;i<maxSize;i++)
        elem[i]=tmp[(front+i)%maxSize];

    front=0; rear=maxSize-1;
    maxSize*=2;

    delete tmp;
}

template<class T>
void seqQueue<T>::enQueue(const T& x)
{
    if((rear+1)%maxSize==front) doubleSpace();
    rear=(rear+1)%maxSize;
    elem[rear]=x;
}

template<class T>
T seqQueue<T>::deQueue()
{
    front=(front+1)%maxSize;
    return elem[front];
}

//The following is the link implementation of queue
template<class T>
class linkQueue:public queue<T>
{
    private:
        struct node
        {
            T data;
            node* next;
            node(const T& x,node* n=nullptr)
            :data(x),next(nullptr){};
            node():next(NULL){};
            ~node(){};
        };
        node* front,rear;
    public:
        linkQueue(){front=rear=NULL;}
        ~linkQueue();
        bool isEmpty() {return front==NULL;}
        void enQueue(const T& x);
        T deQueue();
        T getHead() {return front->data;}
};

template<class T>
linkQueue<T>::~linkQueue()
{
    node* tmp;
    while(front)
    {
        tmp=front;
        front=front->next;
        delete tmp;
    }
}

template<class T>
T linkQueue<T>::deQueue()
{
    node* tmp=front;
    T value=front->data;
    front=front->next;
    if(!front) rear=nullptr;
    delete tmp;
    return value;
}

template<class T>
void linkQueue<T>::enQueue(const T& x)
{
    if(rear==nullptr)
        front=rear=new node(x);
    else 
        rear=rear->next=new node(x);
    return ;
}

class simulator
{
    int arrivalLow;
    int arrivalHigh;
    int serviceTimeLow;
    int serviceTimeHigh;
    int customer;
    public:
        simulator();
        int average() const;
};

simulator::simulator()
{
    cout<<"please input the lower and upper bound of arrival interval:";
    cin>>arrivalLow>>arrivalHigh;
    cout<<"\nplease input the lower and upper bound of service time:";
    cin>>serviceTimeLow>>serviceTimeHigh;
    cout<<"\nplease input the number of customers to be simulated:";
    cin>>customer;
    srand(time(NULL)); //initialize the random generator
}

int simulator::average() const
{
    int currentTime=0;
    int totalWaitTime=0;
    int eventTime;
    linkQueue<int> customerQueue;
    int i;

    for(i=0;i<customer;++i)
    {
        currentTime+=arrivalLow+(arrivalHigh-arrivalLow+1)*rand()/(RAND_MAX+1);
        customerQueue.enQueue(currentTime);
    }

    currentTime=0;
    while(!customerQueue.isEmpty())
    {
        eventTime=customerQueue.deQueue();
        if(eventTime<currentTime) totalWaitTime+=currentTime-eventTime;
        else currentTime=eventTime;
        currentTime+=serviceTimeLow+(serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX+1);


    }
    return totalWaitTime/customer;
}
