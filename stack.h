#include "linked_list.h"
template <typename T>
class Stack
{
    T *stack;
    int tos;
    int size;

public:
    // constructor
    Stack(int size);
    ~Stack();
    // member functions
    void print();
    void push(T ele);
    void pop();
    T top();
    bool isEmpty();
};

// constructor
template <typename T>
Stack<T>::Stack(int size)
{
    this->size = size;
    this->stack = new T[size];
    this->tos = -1;
}
// destructor
template <typename T>
Stack<T>::~Stack()
{
    // std ::cout << "DESTRUCTOR STACK -> " << this << "\n";
    delete this->stack;
}

// print
template <typename T>
void Stack<T>::print()
{
    std ::cout << "STACK\n";
    std ::cout << "------\n";
    for (int i = tos; i > -1; i--)
    {
        std ::cout << "  " << this->stack[i] << "\n";
    }
    std ::cout << "------\n";
}

// push
template <typename T>
void Stack<T>::push(T ele)
{
    // throw error when stack is full
    if (tos + 1 == size)
    {
        throw std ::invalid_argument("STACK OVERFLOW");
    }
    this->stack[++tos] = ele;
}

// pop
template <typename T>
void Stack<T>::pop()
{
    // throw error when the stack is empty
    if (tos == -1)
    {
        throw std::invalid_argument("STACK UNDERFLOW");
    }
    tos--;
}

// top
template <typename T>
T Stack<T>::top()
{
    // throw error when the stack is empty
    if (tos == -1)
    {
        throw std::invalid_argument("STACK UNDERFLOW");
    }
    return this->stack[tos];
}

// isEmpty
template <typename T>
bool Stack<T>::isEmpty()
{
    return tos == -1;
}

// Dynamic Stack
template <typename T>
class StackDynamic
{
    LinkedList<T> stack;

public:
    // constructor
    StackDynamic();
    ~StackDynamic();
    // member function
    void print();
    void push(T ele);
    void pop();
    T top();
    bool isEmpty();
};
// constructor
template <typename T>
StackDynamic<T>::StackDynamic()
{
    std ::cout << "CONSTRUCTOR STACK -> " << this << "\n";
}

// destructor
template <typename T>
StackDynamic<T>::~StackDynamic()
{
    std ::cout << "DESTRUCTOR STACK -> " << this << "\n";
}

// print
template <typename T>
void StackDynamic<T>::print()
{
    this->stack.print();
}

// push
template <typename T>
void StackDynamic<T>::push(T ele)
{
    this->stack.insert(1, ele);
}

// pop
template <typename T>
void StackDynamic<T>::pop()
{
    if (this->stack.getSize())
    {
        this->stack.remove(1);
    }
    throw std::invalid_argument("STACK UNDERFLOW");
}

// top
template <typename T>
T StackDynamic<T>::top()
{
    if (this->stack.getSize())
    {
        return this->stack.get(1);
    }

    throw std::invalid_argument("STACK EMPTY");
}

// isEmpty
template <typename T>
bool StackDynamic<T>::isEmpty()
{
    return this->stack.getSize();
}