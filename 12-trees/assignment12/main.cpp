#include <iostream>

using namespace std;

struct Node
{
    int value;
    int h;
    Node *left;
    Node *right;
};

int size(Node *root)
{
    if (root == nullptr)
        return 0;
    else
        return 1 + size(root->left) + size(root->right);
}

int height(Node *node)
{
    if (node == nullptr)
        return 0;
    else if (node->left == nullptr && node->right == nullptr)
        return node->h;
    else
        if (node->left == nullptr)
            return node->h + height(node->right);
        else if (node->right == nullptr)
            return node->h + height(node->left);
        else
            return max(height(node->left), height(node->right));
}

int leaf(Node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return leaf(root->left) + leaf(root->right);
}

Node * fibonacci(int n, int h)
{
    Node *root = new Node;
    root->h = h;
    if (n == 0)
    {
        root->value = 1;
    }
    else if (n == 1)
    {
        root->value = 1;
    }
    else
    {
        Node * left = fibonacci(n - 1, h + 1);
        Node * right = fibonacci(n - 2, h + 1);
        root->left = left;
        root->right = right;
        root->value = root->left->value + root->right->value;
    }
    return root;
}

string traversPre(Node *root)
{
    string str = "";
    if (root == nullptr)
        return "";
    str += to_string(root->value) + " ";
    if (root-> left != nullptr)
        str += traversPre(root->left);
    if (root->right != nullptr)
        str += traversPre(root->right);
    return str;
}
int main(){
    int n;
    cin >> n;
    Node * root = fibonacci(n, 1);
    string printOut = traversPre(root);
    cout << "Call tree in pre-order: " << printOut << endl;
    cout << "Call tree size: " << size(root) << endl;
    cout << "Call tree height: " << height(root) << endl;
    cout << "Call tree leafs: " << leaf(root) << endl;
}