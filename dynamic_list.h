template <typename T>
class List
{
    T *list;
    int count;
    int size;

public:
    // constructor
    List(int n);
    // member functions
    void print();
    void insert(T ele, int pos);
    void remove(int pos);
    void add(T ele);
    T get(int pos);
};

// Constructor
template <typename T>
List<T>::List(int n)
{
    this->size = n;
    this->list = new T[n];
    this->count = 0;
}

// print
template <typename T>
void List<T>::print()
{
    if (this->size)
    {
        for (int i = 0; i < this->count; i++)
        {
            std ::cout << this->list[i] << "\t";
        }
        std ::cout << "\n";
        return;
    }
    std ::cout << "LIST EMPTY\n";
}

// insert
template <typename T>
void List<T>::insert(T ele, int pos)
{
    if (pos <= 0)
    {
        std ::cout << "NEGATIVE INDEX\n";
        return;
    }

    if (pos > this->count)
    {
        T *newList = new T[2 * (this->size)];
        for (int i = 0; i < this->size; i++)
        {
            newList[i] = this->list[i];
        }
        delete this->list;
        this->list = newList;
        this->size = 2 * (this->size);
    }
    this->list[--pos] = ele;
    this->count = pos + 1;
}

// add
template <typename T>
void List<T>::add(T ele)
{
    if (count == this->size)
    {
        insert(ele, count + 1);
        this->count++;
    }
    this->list[this->count++] = ele;
}

// remove
template <typename T>
void List<T>::remove(int pos)
{
    if (pos < 0)
    {
        std ::cout << "NEGATIVE INDEX\n";
        return;
    }

    for (int i = pos - 1; i < this->count; i++)
    {
        this->list[i] = this->list[i + 1];
    }
    this->count--;
}

// get
template <typename T>
T List<T>::get(int pos)
{
    if (pos > 0 || pos < this->count)
    {
        return this->list[--pos];
    }
}