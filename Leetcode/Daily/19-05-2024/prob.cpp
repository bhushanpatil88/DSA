class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int sac = 1e9;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if( (nums[i]^k) >nums[i] ){
                sum += (nums[i]^k);
                sac = min(sac, (nums[i]^k) -nums[i] );
                cnt++;
            }
            else{
                sum += nums[i];
                sac = min(sac, nums[i]-(nums[i]^k));
            }
        }

        if(cnt%2==0)return sum;

        return sum - sac;
    }
};