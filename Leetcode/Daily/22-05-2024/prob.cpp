class Solution {
public:
    
    void f(int ind, vector<vector<string>>&ans,vector<string>&path,string& s){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(!isPal(s,ind,i))continue;
            path.push_back(s.substr(ind,i-ind+1));
            f(i+1,ans,path,s);
            path.pop_back();
        }
    }

    bool isPal(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    
    
    vector<vector<string>> partition(string s) {
       vector<vector<string>>ans;
       vector<string>path;
       f(0,ans,path,s);

       return ans;     
    }
};