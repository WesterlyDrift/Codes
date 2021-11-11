template<class T>
class list
{
    public:
        virtual void list()=0;
        virtual void clear()=0;
        virtual int length() const=0;
        virtual void insert(int i,const T &x)=0;
        virtual void remove(int)=0;
        virtual int search(const T &)const=0;
        virtual T visit(int) const =0;
        virtual void traverse() const=0;
        virtual ~list(){};
};