#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    bool flag = false;
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* temp = root;
        for(auto &c:word){
            if(!temp->links[c-'a']){
                temp->links[c-'a'] = new Node();
            }
            temp = temp->links[c-'a'];
        }

        temp->flag = true;
    }

    int countPrefixs(string word){
        Node* temp = root;
        int cnt = 0;
        for(auto &c:word){
            if(temp->links[c-'a']){
                temp = temp->links[c-'a'];
                cnt += temp->flag == 1;
            }
            else return 0;
        }

        return cnt;
    }
};

string completeString(int n, vector<string> &a){

    Trie t;
    for(auto &c:a){
        t.insert(c);
    }

    string ans = "";
    int gcnt = 0;
    for(auto &c:a){
        int cnt = t.countPrefixs(c);
        if(cnt!=c.size())continue;
        if(cnt>gcnt){
            ans = c;
            gcnt = cnt;
        }
        else if(cnt==gcnt){
            if(c<ans)ans = c;
        }
    }
    if(ans=="")return "None";
    return ans;
}