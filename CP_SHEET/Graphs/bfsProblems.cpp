#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<pair<int, int>> moves8{
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

auto isValid = [&](int i, int j, int n, int m)
{
    return i >= 0 and j >= 0 and i < n and j < m;
};

map<int,vector<int>>G;

// Rotten Oranges
int RottenOranges(vector<vector<int>> &grid)
{
    int total = 0;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
                total++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }
    int time = 0, cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        cnt += sz;
        while (sz--)
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto [i, j] : moves)
            {
                int nx = i + x;
                int ny = j + y;
                if (isValid(nx, ny, n, m) and grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        if(q.size())time++;
    }
    return total == cnt ? time : -1;
}
// TC - O(N x M x 4)
// SC - O(N x M)


// 0-1 Matrix
vector<vector<int>>nearest01(vector<vector<int>>grid){
    int n = grid.size(); 
    int m = grid[0].size(); 
    vector<vector<int>> vis(n, vector<int>(m, 0)); 
    vector<vector<int>> dist(n, vector<int>(m, 0)); 
    
    queue<pair<pair<int,int>, int>> q; 
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(grid[i][j] == 1) {
                q.push({{i,j}, 0}); 
                vis[i][j] = 1; 
            }
        }
    }
    
    while(!q.empty()) {
        auto [pos,steps] = q.front();
        auto [row,col] = pos;
        q.pop(); 
        dist[row][col] = steps; 
        for(auto [i,j]:moves) {
            int nrow = row + i; 
            int ncol = col + j; 

            if(isValid(nrow, ncol, n,m)
            && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1; 
                q.push({{nrow, ncol}, steps+1});  
            }
        }
    }
    return dist; 
}
// TC - O(N x M x 4)
// SC - O(N x M)


// Flood Fill
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initial_color  = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        if(initial_color == newColor)return image;
            
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = newColor;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto [i,j] : moves){
                int nx = i + x;
                int ny = j + y;
                if(isValid(nx,ny,n,m) and image[nx][ny]==initial_color){
                    image[nx][ny] = newColor;
                    q.push({nx,ny});
                }
            }
        }
        return image;
}
// TC - O(N x M x 4)
// SC - O(N x M)


// Course Scheduling
vector<int> findOrder(int V, map<int,vector<int>>&G)
{
   int indegree[V] = {0};
    for (int i = 0; i < V; i++) {
        for (auto it : G[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : G[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }
    if (topo.size() == V) return topo;
    return {};
}
// TC - O(V + E)
// SC - O(2V)


// Alien dictionary
string AlienDictionary(vector<string> dict, int k) {
    map<int,vector<int>>G;
    int n = dict.size();
    for(int i = 0;i<n-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        for(int j = 0;j<min(s1.size(),s2.size());j++){
            if(s1[j]!=s2[j]){
                G[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    
    vector<int>topo = findOrder(k,G);

    
    string ans = "";
    for(auto it:topo)ans = ans + char(it+'a');
    return ans;
}
// TC - O(K + E)
// SC - O(2K)

void sol()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

//===================================================Main==============================================
signed main()
{
    int T = 1;
    cin >> T;

    while (T--)
        sol();
}
