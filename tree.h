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
        std ::cout << "DELETEING " << this << "\n";
    }
};

// Tree
template <typename T>
class Tree
{
private:
    TreeNode<T> *root;

    // helperFunction
    TreeNode<T> *insertRecHelper(TreeNode<T> *root, T data);
    void inorder(TreeNode<T> *root);
    void preorder(TreeNode<T> *root);
    void postorder(TreeNode<T> *root);

public:
    Tree();
    ~Tree();
    // member functions
    void insert(T data);
    void insertRec(T data);
    int search(T data);
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
    void deleteNodeMerging();
    void deleteNodeCopying();
    void findAndReplace();
    void clear();
};

// constructor
template <typename T>
Tree<T>::Tree()
{
    this->root = nullptr;
}

// destructor
template <typename T>
Tree<T>::~Tree()
{
    std ::cout << "DELETING " << this << "\n";
}

// insert
template <typename T>
void Tree<T>::insert(T data)
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
TreeNode<T> *Tree<T>::insertRecHelper(TreeNode<T> *root, T data)
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
void Tree<T>::insertRec(T data)
{
    this->root = insertRecHelper(this->root, data);
}

// inorder
template <typename T>
void Tree<T>::inorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std ::cout << root->data << "  ";
        inorder(root->right);
    }
}

template <typename T>
void Tree<T>::inorderRecursive()
{
    std ::cout << "INORDER : ";
    inorder(this->root);
    std ::cout << "\n";
}

// preorder
template <typename T>
void Tree<T>::preorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        std ::cout << root->data << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

template <typename T>
void Tree<T>::preorderRecursive()
{
    std ::cout << "PREORDER : ";
    preorder(this->root);
    std ::cout << "\n";
}

// postorder
template <typename T>
void Tree<T>::postorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        std ::cout << root->data << "  ";
    }
}

template <typename T>
void Tree<T>::postorderRecursive()
{
    std ::cout << "POSTORDER : ";
    postorder(this->root);
    std ::cout << "\n";
}

// preorder iterative
template <typename T>
void Tree<T>::preorderIterative()
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
void Tree<T>::postorderIterative()
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
void Tree<T>::inorderIterative()
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
        StackDynamic<TreeNode<T> *> S2;
        StackDynamic<TreeNode<T> *> S3;
        S1.push(root);
        while (S1.isEmpty() == 0)
        {
            TreeNode<T> *tos = S1.top();
            while (tos->left != nullptr)
            {
                S1.push(tos->left);
                tos = tos->left;
            }
            while (S1.isEmpty() == 0 && S1.top()->right == nullptr)
            {
                TreeNode<T> *tos = S1.top();
                S2.push(tos);
                S1.pop();
                if (S1.isEmpty() == 0 && S1.top()->right != nullptr)
                {
                    tos = S1.top();
                    S2.push(tos);
                    S1.pop();
                    S1.push(S2.top()->right);
                }
            }
        }
        while (S2.isEmpty() == 0)
        {
            S3.push(S2.top());
            S2.pop();
        }
        while (S3.isEmpty() == 0)
        {

            TreeNode<T> *tos = S3.top();
            std ::cout << tos->data << "  ";
            S3.pop();
        }
    }
    std ::cout << "\n";
}

// level order traversal
template <typename T>
void Tree<T>::levelOrder()
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