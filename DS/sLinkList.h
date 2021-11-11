#include<iostream>
template<class T>
class sLinkList:public list<T>
{
    private:
        struct node
        {
            T data;
            node* next;
            node(const T &x,node* n=NULL)
            { data=x,next=n;}
            node():next(NULL){}
            ~node(){}
        };
    node* head;// head pointer
    int currentLength;
    node* move(int i) const;//return the address of ith node

    public:
        sLinkList(){}
        ~sLinkList(){clear(); delete head;}
        void clear();
        int length() const {return currentLength;}
        void insert(int i,const T& x);
        void remove(int i);
        int search(const T& x) const;
        T visit(int i) const ;
        void traverse() const;

};

template<class T>
sLinkList<T>::sLinkList()
{
    head=new node;
    currentLength=0;
}

template<class T>
void sLinkList<T>::clear()
{
    node* p=head->next,*q;
    head->next=nullptr;
    while(p!=nullptr)
    {//delete all nodes in the linklist
        q=p->next;
        delete p;
        p=q;
    }
    currentLength=0;
}

template<class T>
sLinkList<T>::node* sLinkList<T>::move(int i)const
{
    node* p=head;
    while(i-->=0)
        p=p->next;
    return p;
}

template<class T>
void sLinkList<T>::insert(int i,const T& x)
{
    node* pos;
    
    pos=move(i-1);
    node* tmp=new node(x,pos->next);
    pos->next=tmp;
    currentLength++;
}

template<class T>
void sLinkList<T>::remove(int i)
{
    node* pos,* delp;
    pos=move(i-1);
    delp=pos->next;
    pos->next=delp->next;
    delete delp;
    --currentLength;
}

template<class T>
int sLinkList<T>::search(const T& x)const
{
    node* p=head->next;
    int i=0;
    while(p!=nullptr&&p->data!=x){p=p->next; ++i;}
    if(p==nullptr) return -1;
    else return i;
}

template<class T>
T sLinkList<T> ::visit(int i) const
{
    return move(i)->data;
}

template<class T>
void sLinkList<T>::traverse() const
{
    node* p=head->next;
    cout<<endl;
    while(p!=nullptr)
    {
        cout<<p->data<<'\0';
        p=p->next;

    }
    cout<<endl;
}