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


// Surrounded Regions
vector<vector<char>> SurroundedRegions(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Recursive Lambda function
    auto dfs = [&](int row, int col, auto &&self) -> void
    {
        vis[row][col] = 1;
        for (auto [i, j] : moves)
        {
            int nrow = row + i;
            int ncol = col + j;
            if (isValid(nrow, ncol, n, m) && !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O')
            {
                self(nrow, ncol, self);
            }
        }
    };

    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && board[0][j] == 'O')
        {
            dfs(0, j, dfs);
        }
        if (!vis[n - 1][j] && board[n - 1][j] == 'O')
        {
            dfs(n - 1, j, dfs);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && board[i][0] == 'O')
        {
            dfs(i, 0, dfs);
        }
        if (!vis[i][m - 1] && board[i][m - 1] == 'O')
        {
            dfs(i, m - 1, dfs);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
    return board;
}
// TC - O(N x M x 4)
// SC - O(2N)

// Number of distinct islands
int Islands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    auto dfs = [&](int x, int y, int x0, int y0, vector<pair<int, int>> path, auto &&self) -> void
    {
        vis[x][y] = 1;
        path.push_back({x - x0, y - y0});
        for (auto [i, j] : moves8)
        {
            int nx = i + x;
            int ny = j + y;
            if (isValid(nx, ny, n, m) and vis[nx][ny] == 0 and grid[nx][ny] == 1)
            {
                self(nx, ny, x0, y0, path, self);
            }
        }
    };
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 and vis[i][j] == 0)
            {
                vector<pair<int, int>> path;
                dfs(i, j, i, j, path, dfs);
                st.insert(path);
            }
        }
    }

    return st.size();
}
// TC - O(N x M x 4)
// SC - O(2N)

//  Find Eventual Safe States
vector<int> safeNodes(int V){
        int n = G.size();
        vector<int>vis(n,0), path(n,0), safe(n,0);
        auto dfs = [&](int node, auto&& self) -> bool{
            vis[node] = 1;
            path[node] = 1;
            safe[node] = 0;
            for(auto it:G[node]){
                if(!vis[it]){
                    if(self(it,self)){
                      safe[node] = 0;
                      return true;  
                    }
                }
                else if(path[it]){
                    safe[node] = 0;
                    return true;
                }
            }
            path[node] = 0;
            safe[node] = 1;
            return false;
        };

        vector<int> safeNodes;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i, dfs);
			}
		}
		for (int i = 0; i < n; i++) {
			if (safe[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
}
// TC - O(V + E)
// SC - O(2V)

// Course Scheduling
vector<int> findOrder(int k, vector<vector<int>>& p) {
    map<int,vector<int>>G;
    for(auto &c:p){
        G[c[1]].push_back(c[0]);
    }
    
    vector<int>vis(k,0), pathVis(k,0);
    stack<int>st;
    auto dfs = [&](int node, auto&& self) -> bool{
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it:G[node]){
            if(!vis[it])
            {
                if(self(it,self))return true;
            }
            else if(pathVis[it])return true;
        }
        st.push(node);
        pathVis[node] = 0;
        return false;
    };
    for(int i = 0;i<k;i++){
        if(!vis[i]){
            if(dfs(i,dfs))return {};
        }
    }

    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;

}
// TC - O(V + E)
// SC - O(2V)


// ALien Dictionary
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
    vector<int>vis(k,0);
    stack<int>st;
    auto dfs = [&](int node, auto&& self) -> void{
        vis[node] = 1;
        for(auto it:G[node]){
            if(!vis[it])self(it,self);
        }
        st.push(node);
    };
    for(int i = 0;i<k;i++){
        if(!vis[i]){
            dfs(i,dfs);
        }
    }
    
    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    string ans = "";
    for(auto it:topo)ans = ans + char(it+'a');
    return ans;
}
// TC - O(V + E)
// SC - O(2V)

void sol()
{
    int n;cin>>n;
    vector<string>v(n);
    for(auto &c:v)cin>>c;
    int k;cin>>k;
    cout<<AlienDictionary(v,k);
}

//===================================================Main==============================================
signed main()
{

    int T = 1;
    cin >> T;

    while (T--)
        sol();
}
