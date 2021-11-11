
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
        seqList(int initSize=10);
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
{
    for (int i=0;i<currentLength&&data[i]!=x;++i);
        if (i==currentLength) 
            return -1;
        else return i;
}
//can be implemented reversedly to zero,with 0 being the lookout 
//so we don't need to compare the subscript in each cycle.

template<class T>
void seqList<T>::traverse() const
{
    cout<<endl;
    for(int i=0;i<currentLength;++i)
        cout<<data[i]<<' ';
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
    if(i<0||i>currentLength-1)
    throw OutOfBound();
    for(int count=i;count<currentLength-1;count++)
        data[count]=data[count+1];
    currentLength--;
    
}
