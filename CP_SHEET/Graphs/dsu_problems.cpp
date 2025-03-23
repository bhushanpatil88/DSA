#include <bits/stdc++.h>


using namespace std;

class DSU {
    
public:
    vector<int> rank, parent, size;
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1, 1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
	
	void Reset(int i){
		parent[i] = i;
	}

    void UnionByRank(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if (u == v) return;
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

     void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if (u == v) return;
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};




vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n  = accounts.size();
    unordered_map<string,int>mp;
    DSU d(n);
    for(int i = 0;i<n;i++){
        for(int j = 1;j<accounts[i].size();j++){
            string c = accounts[i][j];
            if(mp.find(c)==mp.end())mp[c] = i;
            else{
                d.UnionByRank(i, mp[c]);
            }
        }
    }

    vector<string>G[n];
    for(auto it:mp){
        string s = it.first;
        int ind = d.findPar(it.second);
        G[ind].push_back(s);
    }

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++) {
        if (G[i].size() == 0) continue;
        sort(G[i].begin(), G[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for (auto it : G[i]) {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}


 
vector<int> numOfIslands(int n, int m,
                            vector<vector<int>> &operators) {

    auto isValid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };
    DSU ds(n * m);
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    vector<int> ans;
    for (auto it : operators) {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        int dr[] = { -1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int ind = 0; ind < 4; ind++) {
            int adjr = row + dr[ind];
            int adjc = col + dc[ind];
            if (isValid(adjr, adjc)) {
                if (vis[adjr][adjc] == 1) {
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if (ds.findPar(nodeNo) != ds.findPar(adjNodeNo)) {
                        cnt--;
                        ds.UnionByRank(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size();
    DSU ds(n * n);
    auto isValid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    };
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            if (grid[i][j] == 0) continue;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int ind = 0; ind < 4; ind++) {
                int nx = i + dr[ind];
                int ny = j + dc[ind];
                if (isValid(nx, ny) && grid[nx][ny] == 1) {
                    int nodeNo = i * n + j;
                    int adjNodeNo = nx * n + ny;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) continue;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> st;
            for (int ind = 0; ind < 4; ind++) {
                int newr = i + dr[ind];
                int newc = j + dc[ind];
                if (isValid(newr, newc)) {
                    if (grid[newr][newc] == 1) {
                        st.insert(ds.findPar(newr * n + newc));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it : st) {
                sizeTotal += ds.size[it];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }
    
    return mx == 0? n*n : mx;
}


int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = stones.size();
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DSU ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findPar(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
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
