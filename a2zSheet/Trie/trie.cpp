struct Node{
    Node* links[26];
    bool isLeaf = false;
};


class Trie{
    private: Node* root;

    public:
    Trie(){
        root = new Node();
    }

     void insert(string word) {
        Node* temp = root;
        for(char c : word) {
            if(!temp -> links[c - 'a']) {
                temp -> links[c - 'a'] = new Node();
            }
            temp = temp -> links[c - 'a'];
        }
        temp -> isLeaf = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char c : word) {
            if(!temp -> links[c - 'a']) return false;
            temp = temp -> links[c - 'a'];
        }
        return temp -> isLeaf;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char c : prefix) {
            if(!temp -> links[c - 'a']) return false;
            temp = temp -> links[c - 'a'];
        }
        return true;
    }

};