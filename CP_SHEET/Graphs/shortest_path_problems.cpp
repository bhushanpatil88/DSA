#include <bits/stdc++.h>


using namespace std;

map<int,vector<pair<int,int>>>G;


// Word ladder
int wordLadder(string startWord, string targetWord, vector<string>&wordList){
    unordered_set<string>st(wordList.begin(), wordList.end());
    queue<pair<string,int>>q;
    q.push({startWord,1});
    st.erase(startWord);

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        string word = it.first;
        int step = it.second;
        if(word==targetWord)return step;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            for(auto c='a';c<='z';c++){
                word[i] = c;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,step+1});
                }
            }
            word[i] = ch;
        }
    }
    return 0;

}
// N -> size of wordList, M -> lenght of each word
// TC - O(N x M x 26) 
// SC - O(N) unordered_set

vector<vector<string>> wordLadder21(string startWord, string targetWord, vector<string>&wordList){
    unordered_set<string>st(wordList.begin(), wordList.end());
    queue<vector<string>>q;
    vector<string>usedWords;
    q.push({startWord});
    usedWords.push_back(startWord);
    vector<vector<string>> ans;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            vector<string> words = q.front();
            q.pop();
            string word = words.back();
            if(word==targetWord){
                if(ans.size()==0)ans.push_back(words);
                else if (ans[0].size() == words.size()){
                    ans.push_back(words);
                }
            }

            for(int i = 0;i<word.size();i++){
                char ch = word[i];
                for(auto c='a';c<='z';c++){
                    word[i] = c;
                    if(st.find(word)!=st.end()){
                        words.push_back(word);
                        usedWords.push_back(word);
                        q.push(words);
                        words.pop_back();
                    }
                }
                word[i] = ch;
            }
        }
        for(auto it:usedWords)st.erase(it);
    }
    return ans;

}
// N -> size of wordList, M -> lenght of each word
// TC - O(N x M x 26) 
// SC - O(N) unordered_set

map<string,int>mp;
vector<vector<string>> wordLadder22(string startWord, string targetWord, vector<string>&wordList){
    unordered_set<string>st(wordList.begin(), wordList.end());
    queue<string>q;
    q.push(startWord);
    st.erase(startWord);
    vector<vector<string>> ans;

    auto dfs = [&](string word, vector<string>&ds,auto && self) -> void{
        if(startWord==word){
            reverse(ds.begin(),ds.end());
            ans.push_back(ds);
            reverse(ds.begin(),ds.end());
            return;
        }
        int steps = mp[word];
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            for(auto c='a';c<='z';c++){
                word[i] = c;
                if(mp[word]==steps-1){
                    ds.push_back(word);
                    self(word,ds,self);
                    ds.pop_back();
                }
            }
            word[i] = ch;
        }
    };

    while(!q.empty()){
        string word = q.front();
        q.pop();
        int steps = mp[word];
        if(word==targetWord)break;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            for(auto c='a';c<='z';c++){
                word[i] = c;
                if(st.find(word)!=st.end()){
                    mp[word] = steps+1;
                    st.erase(word);
                    q.push(word);
                }
            }
            word[i] = ch;
        }
    }
    if(mp.find(targetWord)!=mp.end()){
        vector<string>ds;
        ds.push_back(targetWord);
        dfs(targetWord, ds, dfs);
    }
    return ans;

}
// N -> size of wordList, M -> lenght of each word
// TC - O(N x M x 26) 
// SC - O(N) unordered_set

// Path with minimum effort
int minEffort(vector<vector<int>>&grid){
    set<pair<int,pair<int,int>>>st;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    st.insert({0,{0,0}});
    vector<pair<int,int>>moves = {{0,1},{1,0},{0,-1},{-1,0}};
    while(!st.empty()){
        auto it = *(st.begin());
        int x = it.second.first, y = it.second.second, diff = it.first;
        st.erase(it);

        if(n-1==x and m-1==y)return diff;

        for(auto move:moves){
            int nx = move.first + x;
            int ny = move.second + y;
            if(nx<0 or nx>=n or ny<0 or ny>=m)continue;

            int newEffort = max(abs(grid[nx][ny] - grid[x][y]), diff);
            if(dist[nx][ny] > newEffort){
                if(dist[nx][ny] != 1e9){
                    st.erase({dist[nx][ny],{nx,ny}});
                }
                
                dist[nx][ny] = newEffort;
                st.insert({dist[nx][ny],{nx,ny}});
            }
        }
        
        
    }

    return 0;
}

// TC - O(N x M x 4 x log(N x M) )
// SC - O(N x M x 4)

// Cheapest Flights Within K Stops
int CheapestFlight(int n, int src, int dest, int k){
    queue<tuple<int,int,int>>q;
    q.push({0,src,0});
    vector<int>dist(n,1e9);
    dist[src] = 0;
    while(!q.empty()){
        auto [stops,node,cost] = q.front();
        q.pop();
        if(stops>k)continue;
        for(auto &[child,wt]:G[node]){
            if(cost + wt < dist[child]){
                dist[child] = cost + wt;
                q.push({stops+1,child,dist[child]});
            }
        }
    }

    return dist[dest]==1e9?-1:dist[dest];
}

// Minimum multiplications to reach end
int minimumMultiplication(vector<int>&arr, int start, int end){
    vector<int>dist(100000,1e9);
    queue<pair<int,int>>q;
    q.push({start,0});
    
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        int num = node.first;
        int steps = node.second;
        
        for(auto it:arr){
            int child = (it*num)%(100000);
            if(dist[child]>steps+1){
                dist[child] = steps+1;
                if(child==end)return steps+1;
                q.push({child,steps+1});
            }
        }
    }
    
    return -1;
}

// Number of Ways to Arrive at Destination
int countPaths(int n, vector<vector<int>>& roads) {
    const int M = 1e9+7;
    map<int,vector<pair<int,int>>>G;
    for(auto &c:roads){
        G[c[0]].push_back({c[1],c[2]});
        G[c[1]].push_back({c[0],c[2]});
    }
    set<pair<long long,int>>st;
    vector<long long>dist(n,LLONG_MAX);
    vector<int>cnt(n, 0);
    dist[0]=0;
    cnt[0] = 1;
    st.insert({0ll,0});
    while(!st.empty()){
        auto it = *(st.begin());
        long long cost = it.first;
        int node = it.second;
        st.erase(it);
        for(auto &it:G[node]){
            long long wt = it.second;
            int child = it.first;

            if(dist[child] >= cost + wt){

                // someone has visited with larger distance so erase it
                if(dist[child]!=1e9){
                    st.erase({dist[child], child});
                }
                if(dist[child] == cost + wt )cnt[child] = (cnt[node] + 0ll + cnt[child])%M;
                else cnt[child] = cnt[node];

                dist[child]= cost + wt;
                st.insert({dist[child],child});
                
            }
            
        }
    }
    return cnt[n-1]%M;
}

void sol(){


    
}

 

//===================================================Main==============================================
signed main() {
  
  
    int T=1;
    cin>>T;
   
    while(T--)
     sol();

}
