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

void LeftView(Node* root,int level = 0,vector<int>ans){
    if(root==nullptr)return;
    if(level==ans.size())ans.push_back(root->data);
    LeftView(root->left,level+1,ans);
    LeftView(root->right,level+1,ans);
}

void RightView(Node* root,int level = 0,vector<int>ans){
    if(root==nullptr)return;
    if(level==ans.size())ans.push_back(root->data);
    RightView(root->right,level+1,ans);
    RightView(root->left,level+1,ans);
}

vector<int> bottomView(Node* root){
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            mpp[line] = node->data;
            // For top view
            // if(mpp.find(line) == mpp.end()){
            //     mpp[line] = node->data;
            // }
            if(node->left != NULL){
                q.push({node->left, line - 1});
            }
            if(node->right != NULL){
                q.push({node->right, line + 1});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }


int main()
{

    return 0;
}