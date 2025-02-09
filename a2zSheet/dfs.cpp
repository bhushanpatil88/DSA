#include <bits/stdc++.h>

using namespace std;
const int N = 1e4+10;
vector<int>vis(N,0), dfsVis(N,0);
vector<int>path;
map<int,vector<int>>G;

vector<pair<int,int>>moves={
  {0,1},{1,0},{0,-1},{-1,0}  
};

// Simple DFS
void dfs(int node){
    vis[node] = 1;
    path.push_back(node);
    for(auto it:G[node]){
        if(!vis[it])dfs(it);
    }
}
// N -> No. of Nodes
// E -> Degree of each node
// TC - O(N + 2E) 
// SC -> O(N) + O(N)

// Cycle detection in undirected graph
bool cycleDFS1(int node, int parent){
    vis[node]=1;
    for(auto it:G[node]){
        if(!vis[it])return cycleDFS1(it,node);
        else if(parent!=it)return true;
    }
    return false;
}
// TC - O(N + 2E) 
// SC -> O(N) + O(N)

// Cycle detection in Directed graph
bool cycleDFS2(int node){
    vis[node]=1;
    dfsVis[node] = 1;
    for(auto it:G[node]){
        if(!vis[it])return cycleDFS2(it);
        else if(dfsVis[it])return true;
    }
    dfsVis[node] = 0;
    return false;
}
// TC - O(N + E) 
// SC -> O(N) + O(N)

// Bipartite Graph
vector<int>color(N,-1);
bool isBipartite(int node, int col){
    color[node] = col;
    for(auto it:G[node]){
        if(color[it]==-1)return isBipartite(it, !col);
        else if(color[it]==col)return false;
    }
    return true;
}
// TC - O(N + E) 
// SC -> O(N) + O(N)

// TOPO Sort
stack<int>st;
void Topo(int node){
    vis[node] = 1;
    for(auto it:G[node]){
        if(!vis[it])dfs(it);
    }
    st.push(node);
}
// TC - O(N + E) 
// SC -> O(N) + O(N) + O(N)


void sol(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    // Count no. of islands
    // int cnt = 0;
    // for(int i = 0;i<n;i++){
    //     if(!vis[i]){
    //         cnt++;
    //         dfs(i);
    //     }
    // }
    // cout<<cnt<<"\n";

    cout<<isBipartite(0,0);
    
}

 

//===================================================Main==============================================
signed main() {

    int T=1;
    cin>>T;
   
    while(T--)
     sol();

}
