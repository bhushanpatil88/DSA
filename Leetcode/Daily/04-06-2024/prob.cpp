class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(auto &c:s){
            mp[c]++;
        }
        int odd = 0;
        int len = 0;
        for(auto &c:mp){
            if(c.second&1){
                if(odd==0){
                    odd = 1;
                    len+= c.second;
                }
                else{
                    len += c.second-1;
                }
            }
            else len += c.second;
        }

        return len;
    }
};