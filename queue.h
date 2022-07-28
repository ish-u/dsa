template <typename T>
class Queue
{
    T *queue;
    int size;
    int front;
    int rear;

public:
    // construtor
    Queue(int n);
    ~Queue();
    // member function
    void print();
    void enqueue(T ele);
    T dequeue();
    T peek();
    bool isEmpty();
};

// constructor
template <typename T>
Queue<T>::Queue(int n)
{
    this->size = n;
    this->queue = new T[n];
    this->front = -1;
    this->rear = -1;
}

// destructor
template <typename T>
Queue<T>::~Queue()
{
    delete this->queue;
}

// print
template <typename T>
void Queue<T>::print()
{
    std ::cout << "QUEUE : \n";
    std ::cout << "------\n";
    if (front != -1 && rear != -1)
    {

        for (int i = rear; i >= front; i--)
        {
            std ::cout << "  " << this->queue[i] << "\t";
        }
    }
    std ::cout << "\n------\n";
}

// enqueue
template <typename T>
void Queue<T>::enqueue(T ele)
{
    if (rear + 1 == size)
    {
        throw std ::invalid_argument("QUEUE EXHAUSTED");
    }

    if (front == rear && front == -1)
    {
        this->queue[0] = ele;
        front++;
        rear++;
    }
    else
    {
        this->queue[++rear] = ele;
    }
}

// dequeue
template <typename T>
T Queue<T>::dequeue()
{
    if (front == rear == -1 || front > rear)
    {
        throw std ::invalid_argument("EMPTY QUEUE");
    }
    else if (front + 1 == size)
    {
        throw std ::invalid_argument("QUEUE EXHAUSTED");
    }
    else
    {
        return this->queue[front++];
    }
}

// peek
template <typename T>
T Queue<T>::peek()
{
    if (!this->isEmpty())
    {
        return this->queue[front];
    }
}

template <typename T>
class CircularQueue
{
    T *queue;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size);
    ~CircularQueue();
    // member functions
    void print();
    void enqueue(T ele);
    void dequeue();
    T peek();
    bool isEmpty();
};

// constructor
template <typename T>
CircularQueue<T>::CircularQueue(int size)
{
    this->size = size;
    this->queue = new T[this->size];
    this->front = -1;
    this->rear = -1;
}
// descrutor
template <typename T>
CircularQueue<T>::~CircularQueue()
{
    delete queue;
}

// print
template <typename T>
void CircularQueue<T>::print()
{
    std ::cout << "QUEUE : \n";
    std ::cout << "------\n";
    if (front != -1)
    {
        int i;
        for (i = rear; i != front; i = (i + 1) % size)
        {
            std ::cout << "  " << this->queue[i] << "\t";
        }
        std ::cout << "  " << this->queue[i] << "\t";
    }
    std ::cout << "\n------\n";
}

// enqueue
template <typename T>
void CircularQueue<T>::enqueue(T ele)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        throw std ::invalid_argument("QUEUE FULL");
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % size;
    this->queue[rear] = ele;
}

// dequeue
template <typename T>
void CircularQueue<T>::dequeue()
{
    if (front == -1)
    {
        throw std::invalid_argument("QUEUE EMPTY");
    }

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

// peek
template <typename T>
T CircularQueue<T>::peek()
{
    if (!this->isEmpty())
    {
        return this->queue[front];
    }
    throw std ::invalid_argument("QUEUE EMPTY");
}

// isEmpty
template <typename T>
bool CircularQueue<T>::isEmpty()
{
    return front == -1;
}