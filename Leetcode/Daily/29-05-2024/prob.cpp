class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        
        reverse(s.begin(),s.end());
        int i = 0;
        while(s[i]=='0'){
            ans++;
            i++;
        }
        if(i==n-1)return ans;
        while(i<n){
            int len = 0;
            while(s[i]=='1' and i<n){
                i++;
                len++;
            }
            if(i<n){
                s[i] = '1';
            }
            ans += len+1;

        }

        return ans;
    }
};