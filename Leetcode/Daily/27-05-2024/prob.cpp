class Solution {
public:
    int specialArray(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());

        int maxi = nums[nums.size()-1];
        for(int i=1;i<=maxi;i++){
            int lb = lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(n-lb == i){
                return i;
            }
        }

        return -1;
    }
};