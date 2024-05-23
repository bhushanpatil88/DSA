class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = pow(2,nums.size())-1;
        vector<vector<int>>ans;
        for(int i=0;i<=sz;i++){
            vector<int>res;
            for(int j=0;j<nums.size();j++){
                if((i>>j)&1){
                    res.push_back(nums[j]);
                }
            }

            ans.push_back(res);
        }


        return ans;
    }
};