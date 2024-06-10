class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int>nums(h.begin(),h.end());

        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            cnt += (h[i]!=nums[i]);
        }

        return cnt;
    }
};