class Solution {
public:

    int f(int ind,vector<int>&nums,int k,unordered_map<int,int>&mp){
        if(ind==nums.size())return 1;
        int t = 0;

        
        if(!mp[nums[ind]+k] and !mp[nums[ind]-k]){
            mp[nums[ind]]++;
            t = f(ind+1,nums,k,mp);
            mp[nums[ind]]--;
        }
    
        int nt = f(ind+1,nums,k,mp);

        return t + nt;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt = f(0,nums,k,mp);

        return cnt-1;
    }
};