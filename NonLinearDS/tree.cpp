#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

class Tree
{
    // instance variables
private:
    node *root;

    // class methods or member functions
private:
    int tree_height(node *);
    node *insert(node *, int);
    void inorder_traverse(node *);
    void preorder_traverse(node *);
    void postorder_traverse(node *);

public:
    Tree() { root = NULL; }
    void insert(int);
    void inorder_traverse();
    void preorder_traverse();
    void postorder_traverse();
};

int Tree::tree_height(node *root_node)
{
    int h = 0;
    if (root_node == NULL)
    {
        return 0;
    }

    h = max(tree_height(root_node->left), tree_height(root_node->right)) + 1;
    return h;
}

void Tree::insert(int num_data)
{
    root = insert(root, num_data);
}

void Tree::inorder_traverse()
{
    inorder_traverse(root);
    cout << endl;
}

void Tree::preorder_traverse()
{
    preorder_traverse(root);
    cout << endl;
}

void Tree::postorder_traverse()
{
    postorder_traverse(root);
    cout << endl;
}

node *Tree::insert(node *root_node, int num_data)
{

    if (root_node == NULL)
    {
        // node *temp = new node();
        node *temp = new node;
        temp->data = num_data;
        temp->left = NULL;
        temp->right = NULL;

        root_node = temp;
        return root_node;
    }
    else if (root_node->left == NULL)
    {
        node *temp = new node;
        temp->data = num_data;
        temp->left = NULL;
        temp->right = NULL;

        root_node->left = temp;
        return root_node;
    }
    else if (root_node->right == NULL)
    {
        node *temp = new node;
        temp->data = num_data;
        temp->left = NULL;
        temp->right = NULL;

        root_node->right = temp;
        return root_node;
    }
    else
    {
        int height_left = tree_height(root_node->left);
        int height_right = tree_height(root_node->right);

        if (height_left <= height_right)
        {
            root_node->left = insert(root_node->left, num_data);
        }
        else
        {
            root_node->right = insert(root_node->right, num_data);
        }
        return root_node;
    }
}

void Tree::inorder_traverse(node *root_node)
{
    if (root_node != NULL)
    {
        inorder_traverse(root_node->left);
        cout << root_node->data << "\t";
        inorder_traverse(root_node->right);
    }
}

void Tree::preorder_traverse(node *root_node)
{
    if (root_node != NULL)
    {
        cout << root_node->data << "\t";
        preorder_traverse(root_node->left);
        preorder_traverse(root_node->right);
    }
}

void Tree::postorder_traverse(node *root_node)
{
    if (root_node != NULL)
    {
        postorder_traverse(root_node->left);
        postorder_traverse(root_node->right);
        cout << root_node->data << "\t";
    }
}

int main()
{
    Tree t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);

    t.inorder_traverse();
    t.preorder_traverse();
    t.postorder_traverse();
    return 0;
}