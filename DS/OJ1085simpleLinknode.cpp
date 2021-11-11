#include<iostream>
#include<vector>

using namespace std;
int n,m;
int op=0;
int op1,op2;
int main()
{
    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];

    while(m-->0)
    {   cin>>op;
        switch(op)
        {
            case 1: 
                cin>>op1>>op2;
                a.insert(a.begin()+op1,op2);
                break;
            case 2:
                cin>>op1;
                a.erase(a.begin()+op1-1);
        }
    }
    int size=a.size();
    cout<<a[0];
    for(int i=1;i<size;i++)
    cout<<' '<<a[i];
    return 0;
}






































/*
using namespace std;
int n,m;

class OutOfBound{};
class IllegalSize{};

template <class T>
class seqList:public list<T>
{
    private:
        T* data;
        int currentLength;
        int maxSize;
        void doubleSpace();
    public:
        seqList(int initSize=100000);
        ~seqList() { delete [] data;}
        void clear() { currentLength=0;}
        int length() const {return currentLength;}
        void insert(int i,const T &x);
        void remove(int i);
        int search(const T &x) const;
        T visit(int i) const {return data[i];}
        void traverse() const;
};

template<class T>
seqList<T>::seqList(int initSize)
{
    if(initSize<0) throw IllegalSize();
    data =new T[initSize];
    maxSize=initSize;
    currentLength=0;
}
template<class T>
int seqList<T>::search(const T& x) const
{   int i;
    for (i=0;i<currentLength&&data[i]!=x;++i);
        if (i==currentLength) 
            return -1;
        else return i;
}
//can be implemented reversedly to zero,with 0 being the lookout 
//so we don't need to compare the subscript in each cycle.

template<class T>
void seqList<T>::traverse() const
{
    //cout<<endl;
    cout<<data[0];
    for(int i=1;i<currentLength;++i)
        cout<<' '<<data[i];
    return;
}

template<class T>
void seqList<T>::insert(int i,const T& x)
{
    if(i<0||i>currentLength) throw OutOfBound();

    if(currentLength==maxSize)
        doubleSpace();
    
    else 
    {
        for(int count=currentLength;count>i;count--)
            data[count]=data[count-1];
        data[i]=x;
        currentLength++;
    }
}

template<class T>
void seqList<T>::doubleSpace()
{
    T* tmp=data;
    maxSize*=2;
    data=new T[maxSize];
    for(int i=0;i<currentLength;i++)
        data[i]=tmp[i];

    delete [] tmp;
}

template<class T>
void seqList<T>::remove(int i)
{
    if(i<1||i>currentLength)
    throw OutOfBound();
    for(int count=i-1;count<currentLength-1;count++)
        data[count]=data[count+1];
    currentLength--;
    
}


int main()
{
    cin>>n>>m;
    int* a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    seqList<int> l;
    
    char s[16]={'0'};
    for(int i=0;i<n;i++)
        l.insert(i,a[i]);

    cin.get();
    while(m-->0)
    {   int j=2;
        int tmp[3]={0};
        cin.getline(s,16);
        
        tmp[0]=s[0]-'0';
        
        for(;s[j]>='0';j++)
        {
            tmp[1]=tmp[1]*10+s[j]-'0';
        }
        if(tmp[0]==1)
        {   j++;
            for(;s[j]>='0';j++)
            tmp[2]=tmp[2]*10+s[j]-'0';
            l.insert(tmp[1],tmp[2]);
        }
        if(tmp[0]==2)
        {
            l.remove(tmp[1]);
        }
    }
    l.traverse();
    delete [] a;
    
    return 0;
    
}
*/


