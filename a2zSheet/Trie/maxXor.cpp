struct Node{
    Node* links[2];
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* temp = root;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!temp->links[bit]){
                temp->links[bit] = new Node();
            }
            temp = temp->links[bit];
        }
    }

    int getMax(int num){
        Node* temp = root;
        int maxi = 0;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            if(temp->links[!bit]){
                maxi |= (1<<i);
                temp = temp->links[!bit];
            }
            else{
                temp = temp->links[bit];
            }
            
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto &c:nums){
            t.insert(c);
        }
        int ans = 0;
        for(auto &c:nums){
            ans = max(ans, t.getMax(c));
        }

        return ans;
    }
};