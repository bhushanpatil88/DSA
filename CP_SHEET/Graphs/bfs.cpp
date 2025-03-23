#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
vector<int>vis(N,0), dfsVis(N,0);
vector<int>path;
map<int,vector<int>>G;

vector<pair<int,int>>moves={
  {0,1},{1,0},{0,-1},{-1,0}  
};

vector<pair<int,int>>moves8{
     {0,1},{1,0},{0,-1},{-1,0}, {1,1},{1,-1},{-1,1},{-1,-1} 
};


// Simple BFS
void bfs(){
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    path.push_back(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:G[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
                path.push_back(it);
            }
        }
    }
}
// N -> No. of Nodes
// E -> Degree of each node
// TC - O(N + 2E) 
// SC -> O(N)


// Bipartite Graph
bool isBipartite(){
    vector<int>color(N,-1);
    queue<int>q;
    q.push(0);
    color[0] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:G[node]){
            if(color[it]==-1){
                q.push(it);
                color[it] = !color[node];
            }
            else if(color[it]==color[node])return false;
        }
    }
    return true;
    
}
// TC - O(N + E) 
// SC -> O(N)


// TOPO sort && Cycle detection in Directed Graph
vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int>indegree(V,0);
        for(int i = 0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        // TOPO array is also the safe nodes array for eventual safe paths problem
        if(topo.size()==V){
            cout<<"No cycle\n";
        }
        return topo;
	}
    // TC - O(N + E)
    // SC - O(2N)





void sol(){

int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout<<isBipartite();

    
}

 

//===================================================Main==============================================
signed main() {
    int T=1;
    cin>>T;
   
    while(T--)
     sol();

}
