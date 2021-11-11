template<class obj>
class vector
{
    private:
        int theSize;
        int theCapacity;
        obj* objs;
    public:
        enum{SPARE_CAPACITY=16};
        explicit vector(int initSize=0);
        //implicit type cast is not permitted!
        vector(const vector& r);
        ~vector();

        const vector& operator=(const vector& r);
        void resize(int newsize);//reset the size of the table
        void reserve(int newCapacity);//reset the capacity of the array
        obj& operator[](int index);
        const obj% operator[](int index) const;
        bool empty() const;
        int size() const;
        int capacity() const;
        //operations on data elements
        void push_back(const obj& x);
        void pop_back();
        const obj& back() const;
        //iterator operations
        typedef obj* iterator;
        typedef const obj* const_iterator;
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

};
// member functions are not implemented!
