template<class T>
class priorityQueue
{
    private:
    int currentSize;
    T* array;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
    public:
        priorityQueue(int capacity=100)
        {
            array=new T[capacity];
            maxSize=capacity;
            currentSize=0;
        }
        priorityQueue(const T data[],int size);
        ~priorityQueue(){ delete[] array;}
        bool isEmpty() const {return currentSize==0;}
        void enQueue(const T& x);
        T deQueue();
        T getHead() cosnt {return array[1];}

};

template<class T>
void priorityQueue<T>::enQueue(const T& x)
{
    if(currentSize==maxSize-1) doubleSpace();

    //percolate upwards
    int hole=++currentSize;
    for(;hole>1;&&x<array[hole/2];hole/=2)
        array[hole]=array[hole/2];
    array[hole]=x;
}

template<class T>
T priorityQueue<T>::deQueue()
{
    T minitem;
    minitem=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
    return minitem;
}

template<class T>
void priorityQueue<T>::percolateDown(int hole)
{
    int child;
    T tmp=array[hole];
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])
            child++;
        if(array[child]<tmp) array[hole]=array[child];
            else break;
    }
    array[hole]=tmp;
}

