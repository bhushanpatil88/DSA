class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for(int i=1;i<(1<<len);i++){
            int x= 0;
            for(int j=0;j<len;j++){
                if((i>>j)&1){
                    x ^= nums[j];
                }
            }
            sum += x;
        }

        return sum;
    }
};