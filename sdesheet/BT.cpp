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

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data;
    inorder(root->left);
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data;
}

void MorrisInorder(Node *root)
{
    if (root == nullptr)
        return;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != nullptr and prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                // cout<<curr->data<<" " for Morris preorder
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

void LeftView(Node *root, int level = 0, vector<int> ans)
{
    if (root == nullptr)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    LeftView(root->left, level + 1, ans);
    LeftView(root->right, level + 1, ans);
}

void RightView(Node *root, int level = 0, vector<int> ans)
{
    if (root == nullptr)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    RightView(root->right, level + 1, ans);
    RightView(root->left, level + 1, ans);
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        // For top view
        // if(mpp.find(line) == mpp.end()){
        //     mpp[line] = node->data;
        // }
        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

vector<vector<int>> findVertical(Node *root)
{
    map<int, map<int, multiset<int>>> nodes;

    queue<pair<Node *, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Node *temp = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(temp->data);

        if (temp->left)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }

        if (temp->right)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

bool getPath(Node *root, vector<int> &arr, int x)
{
    if (!root)
        return false;
    arr.push_back(root->data);
    if (root->data == x)
        return true;

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;

    arr.pop_back();
    return false;
}

int Width(Node *root)
{
    if (!root)
        return 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int ans = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int left, right;
        int mini = q.front().second;
        for (int i = 0; i < sz; i++)
        {
            auto it = q.front();
            q.pop();
            Node *temp = it.first;
            int id = it.second - mini;
            if (i == 0)
                left = id;
            if (i == sz - 1)
                right = id;
            if (temp->left)
            {
                q.push({temp->left, 2 * id + 1});
            }
            if (temp->right)
            {
                q.push({temp->right, 2 * id + 2});
            }
        }
        ans = max(ans, right - left + 1);
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