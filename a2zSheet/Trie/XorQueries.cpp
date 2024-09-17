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
struct ds{
    int x;
    int m;
    int ind;
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        sort(nums.begin(),nums.end());
        vector<ds>Q;
        for(int i=0;i<q.size();i++){
            ds d;
            d.m = q[i][1];
            d.x = q[i][0];
            d.ind = i;
            Q.push_back(d);
        }
        
        sort(Q.begin(),Q.end(),[&](ds d1,ds d2){
            return d1.m<d2.m;
        });

        vector<int>ans(q.size(),0);
        int n = nums.size();
        int ind = 0;
        
        Trie t;
        
        for(auto &c:Q){
            int x = c.x;
            int m = c.m;
            int qInd = c.ind;

            while(ind<n && nums[ind]<=m){
                t.insert(nums[ind]);
                ind++;
            }
            if(ind==0)ans[qInd] = -1;
            else ans[qInd] = t.getMax(x);
        }
        return ans;
    }
};