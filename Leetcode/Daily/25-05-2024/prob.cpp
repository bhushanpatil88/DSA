class Solution {
public:
vector<string>ans;
unordered_map<string,int>mp;
    void f(int i,string s,vector<string>&ds){
        if(i==s.size()){
            string ss="";
            for(int i=0;i<ds.size();i++){
                if(i==ds.size()-1)ss+=ds[i];
                else ss += ds[i]+" ";
            }
            ans.push_back(ss);
            return;

        }
        for(int j=i;j<s.size();j++){
            string ss = s.substr(i,j-i+1);
            if(mp.find(ss)!=mp.end()){
                ds.push_back(ss);
                f(j+1,s,ds);
                ds.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &c:wordDict){
            mp[c]++;
        }
        vector<string>ds;
        f(0,s,ds);

        return ans;
    }
};