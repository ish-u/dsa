#include "stack.h"
#include "queue.h"
template <typename T>
class TreeNode
{
public:
    TreeNode<T> *left;
    TreeNode<T> *right;
    T data;
    // constructor
    TreeNode(T data, TreeNode<T> *left = nullptr, TreeNode<T> *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    // destructor
    ~TreeNode()
    {
        // std ::cout << "DELETEING " << this << "\n";
    }
};

// BInarySearchTree
template <typename T>
class BinarySearchTree
{
private:
    TreeNode<T> *root;

    // helperFunction
    TreeNode<T> *insertRecHelper(TreeNode<T> *root, T data);
    void inorder(TreeNode<T> *root);
    void preorder(TreeNode<T> *root);
    void postorder(TreeNode<T> *root);
    int findHeight(TreeNode<T> *node);
    T max(TreeNode<T> *root);
    T min(TreeNode<T> *root);
    void deleteNodeHelper(TreeNode<T> *root, T ele);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    // member functions
    void insert(T data);
    void insertRec(T data);
    void search(T data);
    void print();
    void inorderRecursive();
    void preorderRecursive();
    void postorderRecursive();
    void inorderIterative();
    void preorderIterative();
    void postorderIterative();
    void levelOrder();
    int leafNodes();
    int internalNodes();
    int height();
    void deleteNode(T ele);
    void findAndReplace();
    void inorderSuccessor(T ele);
};

// constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->root = nullptr;
}

// destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    std ::cout << "DELETING " << this << "\n";
}

template <typename T>
void BinarySearchTree<T>::search(T ele)
{
    TreeNode<T> *temp = root;
    while (temp != nullptr)
    {
        if (temp->data == ele)
        {
            std ::cout << "ELEMENT FOUND\n";
            return;
        }
        if (ele > temp->data)
        {
            temp = temp->right;
        }
        else if (ele < temp->data)
        {
            temp = temp->left;
        }
    }
    std ::cout << "ELEMENT NOT FOUND\n";
}

// insert
template <typename T>
void BinarySearchTree<T>::insert(T data)
{
    /*
        1. Check if root is empty
        2. If root is empty create new node and set it to the root
        3. If root is not empty then iteratively find the node 'insert' which is
           leaf node at which insertion needs to happen
    */
    if (root == nullptr)
    {
        root = new TreeNode<T>(data);
    }
    else
    {
        // finding 'insert' leaf node at which insertion needs to be done
        TreeNode<T> *traverse = root;
        TreeNode<T> *insert = nullptr;
        while (traverse != nullptr)
        {
            insert = traverse;
            if (data <= traverse->data)
            {
                traverse = traverse->left;
            }
            else
            {
                traverse = traverse->right;
            }
        }
        // inserting the new node
        if (data <= insert->data)
        {
            insert->left = new TreeNode<T>(data);
        }
        else
        {
            insert->right = new TreeNode<T>(data);
        }
    }
}

// insert recursively
template <typename T>
TreeNode<T> *BinarySearchTree<T>::insertRecHelper(TreeNode<T> *root, T data)
{
    if (root == nullptr)
    {
        return new TreeNode<T>(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insertRecHelper(root->left, data);
        }
        else
        {
            root->right = insertRecHelper(root->right, data);
        }
    }
    return root;
}

template <typename T>
void BinarySearchTree<T>::insertRec(T data)
{
    this->root = insertRecHelper(this->root, data);
}

// inorder
template <typename T>
void BinarySearchTree<T>::inorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std ::cout << root->data << "  ";
        inorder(root->right);
    }
}

template <typename T>
void BinarySearchTree<T>::inorderRecursive()
{
    std ::cout << "INORDER : ";
    inorder(this->root);
    std ::cout << "\n";
}

// preorder
template <typename T>
void BinarySearchTree<T>::preorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        std ::cout << root->data << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

template <typename T>
void BinarySearchTree<T>::preorderRecursive()
{
    std ::cout << "PREORDER : ";
    preorder(this->root);
    std ::cout << "\n";
}

// postorder
template <typename T>
void BinarySearchTree<T>::postorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        std ::cout << root->data << "  ";
    }
}

template <typename T>
void BinarySearchTree<T>::postorderRecursive()
{
    std ::cout << "POSTORDER : ";
    postorder(this->root);
    std ::cout << "\n";
}

// preorder iterative
template <typename T>
void BinarySearchTree<T>::preorderIterative()
{
    /*
        1. Create a Stack and insert 'root' into the Stack
        2. while Stack is not empty insert
            2.1 Pop the TOS
            2.2 Push TOS->right
            2.3 Push TOS->left
            2.4 Print TOS
    */

    std ::cout << "PREORDER : ";
    if (this->root != nullptr)
    {
        StackDynamic<TreeNode<T> *> S;
        S.push(root);

        while (S.isEmpty() == 0)
        {
            TreeNode<T> *tos = S.top();
            S.pop();
            if (tos->right != nullptr)
            {
                S.push(tos->right);
            }
            if (tos->left != nullptr)
            {
                S.push(tos->left);
            }
            std ::cout << tos->data << "  ";
        }
    }
    std ::cout << "\n";
}

// postorder iterative
template <typename T>
void BinarySearchTree<T>::postorderIterative()
{
    /*
        1. Create two Stack S1 and S2 and insert 'root' into the S1
        2. while S1 is not empty insert
            2.1 Pop the TOS from S1
            2.2 Push TOS->left to S1
            2.3 Push TOS->right to S1
            2.4 Push TOS to S2
        3. while S2 is not empty pop and print TOS
    */

    std ::cout << "POSTORDER : ";
    if (this->root != nullptr)
    {
        StackDynamic<TreeNode<T> *> S1;
        StackDynamic<TreeNode<T> *> S2;
        S1.push(root);

        while (S1.isEmpty() == 0)
        {
            TreeNode<T> *tos = S1.top();
            S1.pop();
            if (tos->left != nullptr)
            {
                S1.push(tos->left);
            }
            if (tos->right != nullptr)
            {
                S1.push(tos->right);
            }
            S2.push(tos);
        }
        while (S2.isEmpty() == 0)
        {
            TreeNode<T> *tos = S2.top();
            S2.pop();
            std ::cout << tos->data << "  ";
        }
    }
    std ::cout << "\n";
}

// inorder iterative
template <typename T>
void BinarySearchTree<T>::inorderIterative()
{
    /*
        1. Create Stack S1 and S2 and insert 'root' into S1
        2. while S1 is not empty
            2.1 Pop TOS
            2.2 Insert the Left Child till we reach NULL
            2.3
    */

    std ::cout << "INORDER : ";
    if (this->root != nullptr)
    {
        StackDynamic<TreeNode<T> *> S1;
        // StackDynamic<TreeNode<T> *> S2;
        // StackDynamic<TreeNode<T> *> S3;
        // S1.push(root);
        TreeNode<T> *tos = root;
        while (S1.isEmpty() == 0 || tos != nullptr)
        {
            while (tos != nullptr)
            {
                S1.push(tos);
                tos = tos->left;
            }
            tos = S1.top();
            S1.pop();
            std ::cout << tos->data << "  ";
            tos = tos->right;
        }
        std ::cout << "\n";
    }
}
// level order traversal
template <typename T>
void BinarySearchTree<T>::levelOrder()
{
    /*
        1. Create a Queue Q and enqueue the root
        2. while the Q is not empty
            2.1 Dequeue and Enqueue the L and R child of returned TreeNode
            2.2 Print the Dequeued Element
    */
    std ::cout << "BFS :";
    if (root != nullptr)
    {
        QueueDynamic<TreeNode<T> *> Q;
        Q.enqueue(this->root);
        while (Q.isEmpty() == 0)
        {
            TreeNode<T> *curr = Q.peek();
            std ::cout << curr->data << "  ";
            Q.dequeue();
            if (curr->left != nullptr)
            {
                Q.enqueue(curr->left);
            }
            if (curr->right != nullptr)
            {
                Q.enqueue(curr->right);
            }
        }
        std ::cout << "\n";
    }
}

// min
template <typename T>
T BinarySearchTree<T>::min(TreeNode<T> *root)
{
    TreeNode<T> *node = root;
    while (node->left != nullptr)
    {
        node = node->left;
    }
    // std ::cout << "MIN : " << node->data << "\n";
    return node->data;
}

// max
template <typename T>
T BinarySearchTree<T>::max(TreeNode<T> *root)
{
    TreeNode<T> *node = root;
    while (node->right != nullptr)
    {
        node = node->right;
    }
    // std ::cout << "MAX : " << node->data << "\n";
    return node->data;
}

// height
template <typename T>
int BinarySearchTree<T>::findHeight(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int heightL = findHeight(root->left);
    int heightR = findHeight(root->right);
    int height = heightL > heightR ? heightL : heightR;
    return 1 + height;
}

template <typename T>
int BinarySearchTree<T>::height()
{
    std ::cout << findHeight(root) << "\n";
    return findHeight(root);
}

// delete and merge
template <typename T>
void BinarySearchTree<T>::deleteNode(T ele)
{
    /*
        1. Search the Node to be deleted
        2.
            2.0 CASE 0 : If Node == 'root' jump to CASE 3
            2.1 CASE 1 : No Child
                Delete the Node as it's a Leaf Node
            2.2 CASE 2 : ONE CHILD
                Set the Child of the Node's Parent as Node's Child
                and delete the Node
            2.3 CASE 3 : 2 CHILD
                     3.1 -> Get the Max Value form LEFT SubTree
                  OR 3.1 -> Get the Min Value from the RIGHT Subtree
                     3.2 -> Replace the Value to Node to be deleted by this Value
                     3.3 -> Recursively Delete the Node with the Value that was used to
                            replace the Node to be deleted
    */
    deleteNodeHelper(this->root, ele);
}

template <typename T>
void BinarySearchTree<T>::deleteNodeHelper(TreeNode<T> *root, T ele)
{
    TreeNode<T> *parent = nullptr;
    TreeNode<T> *node = root;
    int flag = 0;
    while (node != nullptr)
    {
        if (node->data == ele)
        {
            flag = 1;
            break;
        }
        else if (ele > node->data)
        {
            parent = node;
            node = node->right;
        }
        else if (ele < node->data)
        {
            parent = node;
            node = node->left;
        }
    }

    if (flag)
    {
        // CASE 0
        if (root == node)
        {
            T minNodeOnRightSubtree = min(node->right);
            node->data = minNodeOnRightSubtree;
            deleteNodeHelper(node->right, node->data);
        }
        // CASE 1
        else if (node->left == nullptr && node->right == nullptr)
        {
            if (parent->left == node)
            {
                parent->left = nullptr;
            }
            else if (parent->right == node)
            {
                parent->right = nullptr;
            }
            delete node;
        }
        // CASE 2
        else if (node->left == nullptr && node->right != nullptr)
        {
            if (parent->left == node)
            {
                parent->left = node->right;
            }
            else if (parent->right == node)
            {
                parent->right = node->right;
            }
            delete node;
        }
        else if (node->left != nullptr && node->right == nullptr)
        {
            if (parent->left == node)
            {
                parent->left = node->left;
            }
            else if (parent->right == node)
            {
                parent->right = node->left;
            }
            delete node;
        }
        // CASE 3
        else if (node->left != nullptr && node->right != nullptr)
        {
            T minNodeOnRightSubtree = min(node->right);
            node->data = minNodeOnRightSubtree;
            deleteNodeHelper(node->right, node->data);
        }
    }

    throw std ::invalid_argument("ELEMENT NOT FOUND");
}

// inorder successor
template <typename T>
void BinarySearchTree<T>::inorderSuccessor(T ele)
{
    TreeNode<T> *node = root;
    int flag = 0;
    while (node != nullptr)
    {
        if (node->data == ele)
        {
            flag = 1;
            break;
        }
        else if (ele > node->data)
        {
            node = node->right;
        }
        else if (ele < node->data)
        {
            node = node->left;
        }
    }

    if (flag)
    {
        // CASE 1 : RIGHT SUBTREE IS NOT NULL
        if (node->right != nullptr)
        {
            std ::cout << min(node->right) << "\n";
        }
        else
        {
            TreeNode<T> *next;
            TreeNode<T> *curr = this->root;
            while (curr != node)
            {
                if (curr->data > node->data)
                {
                    next = curr;
                    curr = curr->left;
                }
                else if (curr->data < node->data)
                {
                    curr = curr->right;
                }
            }
            std ::cout << next->data << "\n";
        }
    }

    std ::invalid_argument("ELEMENT NOT FOUND");
}