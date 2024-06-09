#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    int ends = 0;
    int pref = 0;
};

class Trie{
    private: Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* temp = root;
        for(auto &c:word){
            if(!temp->links[c-'a']){
                temp->links[c-'a'] = new Node();
            }
            temp = temp->links[c-'a'];
            temp->pref++;
        }

        temp->ends++;

    }

    int countWordsEqualTo(string &word){
        Node* temp = root;
        for(auto &c:word){
            if(temp->links[c-'a']){
                temp = temp->links[c-'a'];
            } else return 0;
        }

        return temp->ends;
    }

    int countWordsStartingWith(string &word){
        Node* temp = root;
        for(auto &c:word){
            if(temp->links[c-'a']){
                temp = temp->links[c-'a'];
            }
            else return 0;
            
        }

        return temp->pref;
    }

    void erase(string &word){
        Node* temp = root;
        for(auto &c:word){
            if(temp->links[c-'a']){
                temp = temp->links[c-'a'];
            }
            temp->pref--;
            
        }
        temp->ends--;
    }
};
