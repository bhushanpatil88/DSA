class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int>costs(n,0);
        for(int i=0;i<n;i++){
            costs[i] = abs(s[i]-t[i]);
        }
        int len = 0;
        int sum = 0;
        int l = 0;
        for(int r=0;r<n;r++){
            sum += costs[r];
            while(sum>maxCost and l<n){
                sum -= costs[l];
                l++;
            }
            len = max(len,r-l+1);
        }

        return len;

    }
};