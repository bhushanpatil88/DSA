class Solution {
public:
    int countTriplets(vector<int>& arr) {
        arr.insert(arr.begin(),0);
        int n = arr.size();
        for(int i=1;i<n;i++)arr[i] ^= arr[i-1];

        int ans = 0;
        unordered_map<int,int>cnt,tot;
        for(int i=0;i<n;i++){
            ans += cnt[arr[i]]++ * (i-1)-tot[arr[i]];
            tot[arr[i]]+=i;
        }

        return ans;

    }
};