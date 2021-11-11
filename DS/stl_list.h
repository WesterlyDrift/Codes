template<class obj>
class list
{
    private:
        struct node
        {
            obj data;
            node* prev,* next;
            node(const obj& x,node* p,node* n):
            data(x),prev(p),next(n){}
            node(){prev=nullptr;next=nullptr;}
            ~node(){}
        };
        int theSize;
        node* head,* tail;
        void init();
    public:
        class const_iterator;
        class iterator:public const_iterator;

        list();
        list(const list& r);
        ~list();

        const list& operator=(const list& r);
        //iterator operations
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

        iterator insert(iterator itr,const obj& x);
        iterator erase(iterator itr);
        iterator erase(iterator start,iterator end);

        int size() const;
        bool empty() const;
        void clear();

        obj& front();
        const obj& front() const;
        void push_front(const obj& x);
        void push_back(const obj& x);
        void pop_front();
        void pop_back();

};