#include"stack.h"

template<class T>
class seqStack:public stack <T>
{
    private:
   
    T* elem;
    int top_p;
    int maxSize;
    void doubleSpace();
   
    public:

    seqStack(int initSize=10);
    ~seqStack();
    bool isEmpty() const;
    void push(const T& x);
    T pop();
    T top() const;
    bool isReverse(char* s);
};

template<class T>
seqStack<T>::seqStack(int initSize)
{
    elem =new T[initSize];
    maxSize=initSize;
    top_p=-1;
}

template<class T>
seqStack<T>::~seqStack()
{
    delete [] elem;
}

template<class T>
bool seqStack<T>::isEmpty()const
{
    return top_p==-1;
}

template<class T>
void seqStack<T>::push(const T& x)
{
    if(top_p=maxSize-1) doubleSpace();
    elem[++top_p]=x;
}

template<class T>
T seqStack<T>::pop()
{
    return elem[top_p--];
}

template<class T>
T seqStack<T>::top() const
{
    return elem[top_p];
}

template<class T>
void seqStack<T>::doubleSpace()
{
    T* temp=elem;
    elem=new T[maxSize*2];
    for(int i=0;i<maxSize;i++)
        elem[i]=temp[i];
    maxSize*=2;
    delete [] temp;
}

template<class T>
bool seqStack<T>::isReverse(char* s)
{
    int len=strlen(s);
    seqStack<char> str(len);
    for(int i=0;i<len;++i)
    {
        str.push(s[i]);
    }
    for(int i=0;i<len;++i)
    if(s[i]!=str.pop()) return false;
    return true;
}