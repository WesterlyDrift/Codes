#include<iostream>

template<class T>
class dLinkList:public list<T>
{
    private:
        struct node
        {
            T data;
            node* prev,* next;
            node(const T& x,node* p=nullptr,node* n=nullptr)
            {
                data=x;next=n,prev=p;
            }
            node():next(nullptr),prev(nullptr){}
            ~node(){}
        };
    node* head,* tail;
    int currentLength;
    node* move(int i) const;
    public:
        dLinkList();
        ~dLinkList(){ clear(); delete head;delete tail;}

        void clear();
        int length() const{return currentLength;}
        void insert(int i,const T& x);
        void remove(int i);
        int search(const T& x) const;
        T visit(int i) const;
        void traverse() const;
};

template<class T>
dLinkList<T>::dLinkList()
{
    head=new node;
    head->next=tail=new node;
    tail->prev=head;
    currentLength=0;
}

template<class T>
void dLinkList<T>::insert(int i,const T& x)
{
    node* pos,* tmp;
    pos=move(i);
    tmp=new node(x,pos->prev,pos);
    pos->prev->next=tmp;
    pos->prev=tmp;
    ++currentLength;

}

template<class T>
void dLinkList<T>::remove(int i)
{
    node* pos=move(i);
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    delete pos;
    --currentLength;
}
