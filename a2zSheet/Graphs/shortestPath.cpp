#include <bits/stdc++.h>


using namespace std;

map<int,vector<pair<int,int>>>G;

// Shortest Path in DAG
vector<int>shortestPathDAG(int N){
    map<int,vector<pair<int,int>>>G;
    int vis[N] = {0};
    stack < int > st;
    auto dfs = [&](int node, auto&& self) -> void{
        vis[node] = 1;
        for(auto it:G[node]){
            if(!vis[it.first])self(it.first,self);
        }
        st.push(node);
    };

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            dfs(i, dfs);
        }
    }
    vector < int > dist(N);
    for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
    }

    dist[0] = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: G[node]) {
            int v = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[v]) {
                dist[v] = wt + dist[node];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
    }
    return dist;
}
// TC - O(V + E)
// SC - O(2V)

vector<int> ShortestPathUnitWeights(int N){
    vector<int>dist(N,1e9);
    dist[0] = 0;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:G[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    return dist;
    
}
// TC - O(V + 2E)
// SC - O(V + 2E)




vector <int> dijkstra(int V){
        
    set<pair<int,int>>st;
    vector<int>dist(V,INT_MAX);
    // vector<int> parent(V+1,0);
    dist[0]=0;
    st.insert({0,0});
    while(!st.empty()){
        auto it = *(st.begin());
        int cost = it.first;
        int node = it.second;
        st.erase(it);
        for(auto &it:G[node]){
            int wt = it.second;
            int child = it.first;

            if(dist[child]>  cost + wt){

                // someone has visited with larger distance so erase it
                if(dist[child]!=1e9){
                    st.erase({dist[child], child});
                }
                dist[child]= cost + wt;
                st.insert({dist[child],child});
                // parent[child] = node;
            }
            
        }
    }
    // int node = V;
    // vector<int>path;
    // while(parent[node]!=node){
    //     path.push_back(node);
    //     node = parent[node];
    // }
    // path.push_back(0);
    // reverse(path.begin(),path.end());
    return dist;
}
// TC - V x (pop from PQ + no. of edges x push to PQ)
// TC - V x [ log(heap_size) + ((V-1) x log(heap_size)) ]
// TC - V x [log(heap_size) x  (1 + V - 1)]
// TC - V x [log(heap_size) x V]
// TC - V^2 x log(heap_size)
// TC - V^2 x log(V^2)  heap_size -> total number of edges
// TC - O(V^2 x Log(V^2) )
// TC - O(V^2 x 2 Log(V) )
// TC - O(E x 2 x log(V) )
// TC - O(E x log(V) )  where E = V^2
// SC - O(E)


// Bellman-Ford
vector<int> bellmanFord(int V,vector<vector<int>>&edges, int src) {
    vector<int>dist(V,1e8);
    dist[src] = 0;
    for(int i = 0;i<V-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt= it[2];
            if(dist[u]!=1e8 and dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt= it[2];
        if(dist[u]!=1e8 and dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;

}
// TC - O(V x E)
// SC - O(E)


// Floyd Warshall
void Floyd_Warshall(vector<vector<int>>&matrix){
    int n  = matrix.size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]==-1)matrix[i][j]=1e9;
            if(i==j)matrix[i][j] = 0;
        }
    }

    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
            }
        }
    }
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
