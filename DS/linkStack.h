#include<iostream>
#include"stack.h"

template<class T>
class linkStack:public stack<T>
{
    private:
    struct node
    {
        T data;
        node* next;
        node(const T& x,node* n=NULL):data(x),next(n){};
        node():next(nullptr){};
        ~node(){};
    };
    node* top_p;
    
    public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const T& x);
    T pop();
    T top() const;

};

template<class T>
linkStack<T>::linkStack()
{
    top_p=nullptr;
}

template<class T>
linkStack<T>::~linkStack()
{
    node* tmp;
    while(top_p)
    {
        tmp=top_p;
        top_p=top_p->next;
        delete tmp;
    }
}

template<class T>
void linkStack<T>::push(const T& x)
{   
    top_p=new node(x,top_p);
}

template<class T>
T linkStack<T>::pop()
{
    node* tmp = top_p;
    T x=tmp->data;
    top_p=top_p->next;
    delete tmp;
    return x;
}

template<class T>
T linkStack<T>::top() const
{
    return top_p->data;
}

template<class T>
bool linkStack<T>::isEmpty() const
{
    return top_p==nullptr;
}

void PrintNum(int num)
{
    linkStack<int> s;
    int tmp;
    s.push(num);

    while(!s.isEmpty())
    {
        tmp=s.pop();
        if(tmp>9)
        {
            s.push(tmp%10);
            s.push(tmp/10);
        }
        else std::cout.put(tmp+'0');
    }
}