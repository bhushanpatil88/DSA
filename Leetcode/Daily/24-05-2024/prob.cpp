class Solution {
public:
    int ans = 0;
    int a[26],b[26];
    void f(int ind,vector<string>&words,vector<int>&score){
        if(ind==words.size()){
            int s = 0;
            for(int i=0;i<26;i++){
                if(b[i]>a[i])return;
                s+= score[i]*b[i];
            }

            ans = max(ans,s);
            return;
        }
        for(auto &c:words[ind]){
            b[c-'a']++;
        }
        f(ind+1,words,score);
        for(auto &c:words[ind]){
            b[c-'a']--;
        }

        f(ind+1,words,score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        for(auto &c:letters)a[c-'a']++;
        f(0,words,score);

        return ans;
    }
};