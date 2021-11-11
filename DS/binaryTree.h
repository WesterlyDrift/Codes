#include"queue.h"
#include"linkStack.h"
template<class T>
class binaryTree
{
    private:
        struct node
        {
            node* left,* right;
            T data;
            node():left(nullptr),right(nullptr){};
            node(T item,node* l=nullptr,node* r=nullptr)
            :data(item),left(l),right(r){};
            ~node(){};
        };
        node* root;

        struct stnode //used for non-recuresive midorder traversal
        {
            node* nd;
            int timespop;
            stnode(node* n=nullptr):node(n),timespop(0){};
        };
    public:
        binaryTree():root(nullptr){};
        binaryTree(const T& x)
        {
            root=new node(x);
        }
        ~binaryTree() {clear();}

        T getRoot() const{return root->data;}
        T getLeft() const {return root->left->data;}
        T getRight() const {return root->right->data;}

        void makeTree(const T& x,binaryTree& lt,binaryTree& rt)
        {
            root=new node(x,lt.root,rt.root);
            lt.root=nullptr;
            rt.root=nullptr;

        }

        void delLeft()
        {
            binaryTree tmp=root->left;
            root->left=nullptr;
            tmp.clear();
        }

        void delRight()
        {
            binaryTree tmp=root->right;
            root->right=nullptr;
            tmp.clear();
        }
        
        bool isEmpty() const {return root==nullptr;}

        void clear() { if(root) clear(root); root=nullptr;}

        int size() const {return size(root);}
        
        int height() const { return height(root);}

        void preOrder() const
        {
            if(root)
            {
                cout<<"Preorder traverse:";
                preOrder(root);
            }
        }

        void postOrder() const
        {
            if(root)
            {
                cout<<"Postorder traverse:";
                postOrder(root);
            }

        }

        void midOrder() const
        {
            if(root)
            {
                cout<<"Midorder traverse:";
                midOrder(root);
            }
        }

        void createTree(T flag);

        void preOrder1() const;
        void midOrder1() const;
        void postOrder1() const;

    private:
        int height(node* t) const
        {
            if(!t) return 0;
            else 
            {
                int lt=height(t->left);
                int rt=height(t->right);
                return 1+((lt>rt)?lt:rt);
            }
        }

        void clear(node* t)
        {
            if(t->left) clear(t->left);
            if(t->right) clear(t->right);
            delete t;
        }

        int size(node* t) const
        {
            if(!t) return 0;
            return 1+size(t->left)+size(t->right);

        }

        void preOrder(node* t) const
        {
            if(t) 
            {
                cout<<t->data<<' ';

            
            preOrder(node* t->left);
            preOrder(node* t->right);
            }
            return ;
        }

        void postOrder(node* t) const
        {
            if(t)
            {
                postOrder(t->left);
                postOrder(t->right);
                cout<<t->data<<' ';
            }
        }

        void midOrder(node* t) const
        {
            if(t)
            {
                midOrder(t->left);
                cout<<t->data<<' ';
                midOrder(t->right);
            }
        }

        
};

template<class T>
void binaryTree<T>::createTree(T flag) 
{
    linkQueue<node*> que;
    node* tmp;
    T x,ldata,rdata;

    cout<<"\ninput the root":;
    cin>>x;
    root=new node(x);
    que.enQueue(root);

    while(!que.isEmpty())
    {
        tmp=que.deQueue();
        cout<<"\ninput the two sons of "<<tmp->data<<" and type "<<flag<<" for NULL node";
        cin>>ldata>>rdata;
        if(ldata!=flag) que.enQueue(tmp->left=new node(ldata));
        if(rdata!=flag) que.enQueue(tmp->right=new node(rdata));
    }
    cout<<"\ncreation completed!";
}

//test program
int main()
{
    binaryTree<char> tree,tree1('M'),tree2;

    tree.createTree('@');

    cout<<"the height is: "<<tree.height()<<endl;
    cout<<"the size is: "<<tree.size()<<endl;
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();

    tree2.makeTree('Y',tree,tree1);
    cout<<endl;
    cout<<"the height is: "<<tree2.height()<<endl;
    cout<<"the size is: "<<tree2.size()<<endl;
    tree2.preOrder();
    tree2.midOrder();
    tree2.postOrder();

    return 0;
}

//non-recursive implementation of travesal in 3 orders
template<class T>
void binaryTree<T>::preOrder1() const
{
    linkStack<node*> s;
    node* current;

    cout<<"Preorder Traversal:";
    s.push(root);
    while(!s.isEmpty())
    {
        current=s.pop();
        cout<<current->data;
        if(current->right) s.push(current->right);
        if(current->left) s.push(current->left);
        
    }
}

template<class T>
void binaryTree<T>::midOrder1() const
{
    linkStack<node*> s;
    stnode current(root);

    cout<<"Midorder traversal:";
    s.push(root);
    while(!s.isEmpty())
    {
        current=s.pop();
        if(++current.timespop==2)// Second pop can be visited
        {
            cout<<current.nd->data;
            if(current.nd->right)
                s.push(current.nd->right);
        }
            else //first pop should be re-pushed
            {
                s.push(current);
                if(current.nd->left)
                    s.push(current.nd->left);
            }
    }

    
}

template<class T>
void binaryTree<T>::postOrder1() const
{
    linkStack<stnode> s;
    stnode current(root);

    cout<<"Postorder Traversal in non-recursive approach:";
    s.push(current);

    while(!s.isEmpty())
    {
        current=s.pop();
        if(++current.timespop==3)
        {
            cout<<current.nd->data;
            continue;
        }
        s.push(current);
        if(current.timespop==1)
        {
            if(current.nd->left)
            s.push(stnode(current.nd->left));
        }
        else 
        {
            if(current.nd->right)
            s.push(stnode(current.nd->right));
        }
    }
}

//Calculator
class calc
{
    enum Type{DATA,ADD,SUB,MULTI,DIV,OPAREN,CPAREN,EOL};
    
    struct node
    {
        Type type;
        node *lchild,*rchild;
        int data;
        node(Type t,int d=0,node*lc=nullptr,node*rc=nullptr)
        {
            type=t;
            data=d;
            lchild=lc;
            rchild=rc;
        }

    };
    node* root;
    node* create(char* &s);
    Type getToken(char* &s,int &value);
    int result(node* t);
    public:
        calc(char* s) { root=create(s);}
        int result() { if(!root) return 0;  return result(root);}
};

calc::node* calc::create(char* &s)
{
    node* p,*root=NULL;
    Type returnType;
    int value;

    while(*s)
    {
        returnType=getToken(s,value);

        switch(returnType)
        {
            case DATA:
            case OPAREN:
                if(returnType==DATA) p=new node(DATA,value);
                    else p=create(s);
                if(!root) root=p;
                    else if(!root->rchild) root->rchild=p;
                        else root->rchild->rchild=p;
            break;

            case CPAREN:
            case EOL: return root;
            case ADD:
            case SUB:
                root=new node(returnType,0,root);
            break;

            case MULTI:
            case DIV:
                if(root->type==DATA||root->type==MULTI||root->type==DIV)
                    root=new node(returnType,0,root);
                else root->rchild=new node(returnType,0,root->rchild);


        }
    }
    
    return root;
}

calc::Type calc::getToken(char* &s,int &data)
{
    char type;
    while(*s==' ') ++s;
    if(*s>='0'&&*s<='9') //meet with operand
    {
        data=0;
        while(*s>='0'&&*s<='9')
        {
            data=data*10+*s-'0';
            ++s;
        }
        return DATA;
    }

    if(*s=='\0') return EOL;

    type=*s;
    ++s;
    switch(type)
    {
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MULTI;
        case '/': return DIV;
        case '(': return OPAREN;
        case ')': return CPAREN;
        default: return EOL;
    }
}

int calc::result(node* t)
{
    int num1,num2;

    if(t->type==DATA) return t->data;
    num1=result(t->lchild);
    num2=result(t->rchild);
    switch(t->type)
    {
        case ADD: t->data=num1+num2; break;
        case SUB: t->data=num1-num2; break;
        case MULTI: t->data=num1*num2; break;
        case DIV: t->data=num1/num2; break;
    }
    return t->data;
}


//test program for mid-order calculator 
int main()
{
calc exp("2*3+(1*2*3+6*6*(2*3/5+2/2");
cout<<exp.result()<<endl;
return 0;
}


template<class T>
class huffman
{
    private:
        struct node
        {
            T data;
            int weight;
            int parent,left,right;
        };

        node* elem;
        int length;
    public:
        struct hfcode
        {
            T data;//char to be encoded
            string code;//corresponding huffman code
        };

        huffman(const T* x,const int* w,int size);
        void getCode(hfcode result[]);
        ~huffman(){ delete [] elem;}

};

template<class T>
huffman<T>::huffman(const T* v, const int* w,int size)
{
    const int MAX_INT=32767;
    int min1,min2;
    int x,y;//the suffixes of 2 smallest trees

    //initialization
    length=2*size;
    elem=new node[length];
    for(int i=size;i<length;++i)
    {
        elem[i].weight=w[i-size];
        elem[i].data=v[i-size];
        elem[i].parent=elem[i].left=elem[i].right=0;
    }

    //merge trees in the forest
    for(int i=size-1;i>0;--i)
    {
        min1=min2=MAX_INT;
        x=y=0;
        for(int j=i+1;j<length;++j)
            if(elem[j].parent==0)
                if(elem[j].weight<min1)
                {
                    min2=min1;
                    min1=elem[j].weight;
                    x=y;
                    y=j;
                }
                else if(elem[j].weight<min2)
                {
                    min2=elem[j].weight;
                    x=j;
                }
        elem[i].weight=min1+min2;
        elem[i].left=x;
        elem[i].right=y;
        elem[i].parent=0;
        elem[x].parent=i;
        elem[y].parent=i;
    }
}

template<class T>
void huffman<T>::getCode(hfcode result[])
{
    int size=length/2;
    int p,s;//p for parent and s for current in process
    for(int i=size;i<length;++i)
    {
        result[i-size].data=elem[i].data;
        result[i-size].code="";
        p=elem[i].parent;
        s=i;
        while(p) // trace back to the root
        {
            if(elem[p].left==s)
                result[i-size].code='0'+result[i-size].code;
            else result[i-size].code='1'+result[i-size].code;

            s=p;
            p=elem[p].parent;
        }
    }
}
//Three ways to represent a Tree:
//1. Children-Chain 
//2. Children-Brother
//3. Parent 
