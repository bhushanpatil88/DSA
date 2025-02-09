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
        int u = findPar(u);
        int v = findPar(v);
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

// Prim's Algorithm for MST

map<int,vector<pair<int,int>>>G;

int spanningTree(int V){
    set<pair<int,int>>st;
    vector<int>vis(V,0);
    st.insert({0,0});
    int sum = 0;
    while(!st.empty()){
        auto it = *(st.begin());
        st.erase(it);
        auto [node,wt] = it;
        if(vis[node]==1)continue;
        vis[node] = 1;
        sum += wt;
        for(auto it:G[node]){
            auto [child,child_wt] = it;
            if(!vis[child]){
                st.insert({child_wt,child});
            }
        }
    }
    return sum;
}
// TC - O(E x log(E))
// SC - O (E + V)

//Kruskal's Algorithm
int spanningTree1(int V){
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++) {
        for (auto it : G[i]) {
            auto [child,wt] = it;
            int node = i;
            edges.push_back({wt, {node, child}});
        }
    }
    DSU ds(V);
    sort(edges.begin(), edges.end());
    int mstWt = 0;
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findPar(u) != ds.findPar(v)) {
            mstWt += wt;
            ds.UnionByRank(u, v);
        }
    }

    return mstWt;
}
// TC -  O(N+E) + O(E logE) + O(E*4α*2)
// SC - O(N) + O(N) + O(E)

void sol(){


    
}

 

//===================================================Main==============================================
signed main() {
  
    int T=1;
    cin>>T;
   
    while(T--)
     sol();

}