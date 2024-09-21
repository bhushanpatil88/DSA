#include <bits/stdc++.h>
using namespace std;

int n;

vector<int>ans,v;
void subsetSum(int ind,int sum){
    if(ind==v.size()){
        ans.push_back(sum);
        return;
    }
    subsetSum(ind+1,sum+v[ind]);
    subsetSum(ind+1,sum);
}


vector<vector<int>>subsets;
void generateSubsets(int ind,vector<int>&ds){
    subsets.push_back(ds);

    for(int i=ind;i<v.size();i++){
        if(i!=ind && v[i]==v[i-1])continue;
        ds.push_back(v[i]);
        generateSubsets(i+1,ds);
        ds.pop_back();
    }
}
void combinationSum1(int ind,int target,vector<int>&ds){
    if(ind>v.size())return;
    if(target==0){
        subsets.push_back(ds);
        return;
    }
    
    if (v[ind] <= target) {
        ds.push_back(v[ind]);
        combinationSum1(ind,target-v[ind],ds);
        ds.pop_back();
    }
    combinationSum1(ind+1,target, ds);
}

void combinationSum2(int ind,int target,vector<int>&ds){
    if(target==0){
        subsets.push_back(ds);
            return;
    }
    for(int i = ind;i<v.size();i++){
        if(i!=ind && v[i]==v[i-1])continue;
        if(v[i]<=target){
            ds.push_back(v[i]);
            combinationSum2(i,target-v[i],ds);
            ds.pop_back();
        }
    }
}

vector<vector<string>>pals;
bool isPal(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end])return false;
        start++,end--;
    }
    return true;
}
void palindromicPartition(int ind,string s,vector<string>&ds){

    if(ind==s.size()){
        pals.push_back(ds);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(isPal(s,ind,i)){
            ds.push_back(s.substr(ind,i-ind+1));
            palindromicPartition(i+1,s,ds);
            ds.pop_back();
        }
    }
}

void KthPermutation(int n,int k){
    int fact = 1;
    vector<int>nums;
    for(int i=1;i<n;i++){
        fact*=i;
        nums.push_back(i);
    }
    nums.push_back(n);
    string ans =  "";
    k--;
    while(1){
        ans += to_string(nums[k/fact]);
        nums.erase(nums.begin() + k/fact);
        if(nums.size()==0)break;
        k %= fact;
        fact /= nums.size(); 
    }
    cout<<ans<<'\n';
}

vector<vector<int>>perts;
void AllPermutation(int ind,vector<int>&ds){
    if(ind==ds.size()){
        perts.push_back(ds);
        return;
    }
    for(int i =ind;i<ds.size();i++){
        swap(ds[i],ds[ind]);
        AllPermutation(ind+1,ds);
        swap(ds[i],ds[ind]);
    }
}

vector<vector<string>>NQueens;
vector<bool>row,lowerDiag,upperDiag;

void Queens(int col,vector<string>&ds){
    if(col == ds.size()){
        NQueens.push_back(ds);
        return;
    }
    for(int i=0;i<ds.size();i++){
        if(row[i]==0 and lowerDiag[i+col]==0 and upperDiag[n-1 + col-i]==0){
            ds[i][col] = 'Q';
            row[i]=1,lowerDiag[i+col]=1,upperDiag[n-1+col-i]=1;
            Queens(col+1,ds);
            ds[i][col] = '.';
            row[i]=0,lowerDiag[i+col]=0,upperDiag[n-1+col-i]=0;

        }  
    }
}

bool isSudokoSafe(int r,int c,char ch,vector<vector<char>>board){
    for(int i =0;i<9;i++){
        if(board[i][c]==ch)return false;

        if(board[r][i]==ch)return false;

        if(board[3*(r/c) + i/3][3*(c/3)+ i%3]==ch)return false;
    }
    return true;
}

bool SudokoSolver(vector<vector<char>>&board){
    for(int i=0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(board[i][j]=='.'){
                for(char k='0';k<='9';k++){
                    if(isSudokoSafe(i,j,k,board)){
                        board[i][j] = k;
                        if(SudokoSolver(board))
                            return true;
                        else board[i][j] = '.';
                    }
                }
            }
            
        }
    }
    return false;
}

bool isColorSafe(int node, int col, vector<int>&color, vector<int>G[]){
    for(auto it:G[node]){
        if(color[it]==col)return false;
    }
    return true;
}

bool MColoring(int node, int m, vector<int>&color,vector<int>G[]){
    if(node==n) return true;

    for(int i = 1;i<=m;i++){
        if(isColorSafe(node,i,color,G)){
            color[node]=i;
            if(MColoring(node+1,m,color,G))return true;
            color[node]=0;
        }
    }
    return false;
}

vector< pair<pair<int,int>,char> >moves={
    {{1,0},'D'},{{0,-1},'L'},{{0,1},'R'},{{-1,0},'U'}
};
int vis[1000][1000];
int maze[1000][1000];

vector<string>RatPaths;
bool RatInMaze(int i,int j, string& path){
    if(i==n-1 and j==n-1){
        RatPaths.push_back(path);
        return;
    }

    for(auto &[point,ch]:moves){
        int x = point.first + i;
        int y = point.second + j;
        if(x>=0 and y>=0 and x<n and y<n and !vis[x][y] and maze[x][y]==1){
            vis[x][y]=1;
            path += ch;
            if(RatInMaze(x,y,path))return true;
            vis[x][y]=0;
            path.pop_back();
        }
    }
    return false;
}

int main()
{
  cin>>n;
    // v.resize(n);
    // for(auto &c:v)cin>>c;
    // vector<int>ds;
    // sort(v.begin(),v.end());
    // combinationSum2(0,7,ds);
    // for(auto &c:ans){
    //     cout<<c<<" ";
    // }
    // string s;
    // cin>>s;
    // vector<string>ds;
    // palindromicPartition(0,s,ds);

    // for(auto &c:pals){
    //     for(auto &d:c){
    //         cout<<d<<" ";
    //     }
    //     cout<<'\n';
    // }
    // int k;cin>>k;
    // KthPermutation(n,k);
    
    // vector<int>ds;
    // for(int i=1;i<=n;i++)ds.push_back(i);

    // AllPermutation(0,ds);
    
    // for(auto &c:perts){
    //     for(auto &d:c)cout<<d<<" ";
    //     cout<<'\n';
    // }
    
    // vector<string>ds(n);
    // string s(n,'.');
    // for(int i =0;i<n;i++){
    //     ds[i] = s;
    // }
    // row.assign(n+1,0);
    // lowerDiag.assign(2*n-1,0);
    // upperDiag.assign(2*n-1,0);
    // Queens(0,ds);

    // for(auto &c:NQueens){
    //     for(auto &s:c){
    //         cout<<s<<'\n';
    //     }
    //     cout<<"==============\n";
    // }


    return 0;
}