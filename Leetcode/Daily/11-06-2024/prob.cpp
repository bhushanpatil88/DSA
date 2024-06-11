class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto &c:arr1)mp[c]++;

        vector<int>ans;
        for(auto &c:arr2){
            int val = mp[c];
            mp[c] = 0;
            while(val--)ans.push_back(c);
        }
        for(auto &c:mp){
            if(c.second!=0){
                int val = c.second;
                while(val--)ans.push_back(c.first);
            }
        }
        return ans;

        return ans;
    }
};