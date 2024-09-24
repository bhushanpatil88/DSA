#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int height(Node *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

int diameter(Node *root, int &d)
{
    if (!root)
        return 0;

    int lh = diameter(root->left, d);
    int rh = diameter(root->right, d);
    d = max(d, 1 + lh + rh);
    return 1 + max(lh, rh);
}

int heightBalanced(Node *root)
{
    if (!root)
        return 0;

    int lh = heightBalanced(root->left);
    // if left or right is unbalanced no need to check below
    if (lh == -1)
        return -1;
    int rh = heightBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

Node *LCA(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    Node *left = LCA(root->left, p, q);
    Node *right = LCA(root->right, p, q);

    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    return 0;
}