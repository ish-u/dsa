template <typename T>
class Node
{

public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList
{
    Node<T> *head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    // member function
    void print();
    void add(T ele);
    void insert(int pos, T ele);
    void remove(int pos);
    T get(int pos);
    void set(int pos, T ele);
    void reverseItr();
    void reverseRec();
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    std ::cout << "DESTRUCTOR\n";
}

// print
template <typename T>
void LinkedList<T>::print()
{
    Node<T> *temp = head;
    std ::cout << "LINKED LIST : ";
    while (temp != nullptr)
    {
        std ::cout << temp->data << "  ";
        temp = temp->next;
    }
    std ::cout << "\n";
}

// add
template <typename T>
void LinkedList<T>::add(T ele)
{
    if (head == nullptr)
    {
        head = new Node<T>(ele);
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new Node<T>(ele);
    }
    this->size++;
}

// insert
template <typename T>
void LinkedList<T>::insert(int pos, T ele)
{

    // handling out of bounds 'pos'
    if (head != nullptr && (pos > size + 1 || pos < 1))
    {
        std ::cout << "OUT OF BOUNDS\n";
        return;
    }

    // handling empty list
    if (head == nullptr && pos > 1)
    {
        std ::cout << "LIST EMPTY\n";
        return;
    }

    // insert at beginning in an empty list
    if (head == nullptr && pos == 1)
    {
        head = new Node<T>(ele);
    }
    // insert at the beginning in a non-empty list
    else if (head != nullptr && pos == 1)
    {
        Node<T> *temp = new Node<T>(ele);
        temp->next = head;
        head = temp;
    }
    // insret b/w 2 and 'size'
    else
    {
        Node<T> *temp = new Node<T>(ele);
        int count = 2;
        Node<T> *prev = head;
        Node<T> *curr = head->next;
        while (count != pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = temp;
        temp->next = curr;
    }
    this->size++;
}

// remove
template <typename T>
void LinkedList<T>::remove(int pos)
{
    // handling out of bounds 'pos'
    if (pos > size || pos < 0)
    {
        std ::cout << "OUT OF BOUNDS\n";
        return;
    }

    // handling empty list
    if (head == nullptr)
    {
        std ::cout << "LIST EMPTY\n";
        return;
    }

    // delete the head
    if (pos == 1)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    // delete the bw 2 and 'size'
    else
    {
        int count = 2;
        Node<T> *prev = head;
        Node<T> *curr = head->next;
        while (count != pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        Node<T> *temp = curr;
        prev->next = curr->next;
        delete temp;
    }
    this->size--;
}

// get
template <typename T>
T LinkedList<T>::get(int pos)
{
    // handling out of bounds 'pos'
    if (pos > size || pos < 1)
    {
        throw "OUT OF BOUNDS";
    }

    // handling empty list
    if (head == nullptr)
    {
        throw "LIST EMPTY";
    }

    Node<T> *temp = head;
    int count = 1;
    while (count != pos)
    {
        temp = temp->next;
        count++;
    }

    return temp->data;
}

template <typename T>
void LinkedList<T>::set(int pos, T ele)
{
    // handling out of bounds 'pos'
    if (pos > size || pos < 1)
    {

        throw "OUT OF BOUNDS";
    }

    // handling empty list
    if (head == nullptr)
    {
        throw "LIST EMPTY";
    }

    Node<T> *temp = head;
    int count = 1;
    while (count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->data = ele;
}

// reverse itervative
template <typename T>
void LinkedList<T>::reverseItr()
{
    if (head == nullptr || this->size == 1)
    {
        return;
    }

    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// reverse recursive
template <typename T>
void reverseLL(Node<T> *node)
{
    if (node != nullptr && node->next != nullptr)
    {
        reverseLL(node->next);
        Node<T> *next = node->next;
        next->next = node;
    }
}

template <typename T>
void LinkedList<T>::reverseRec()
{
    Node<T> *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    reverseLL(head);
    head->next = nullptr;
    head = tail;
}