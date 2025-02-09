#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//==============================================DEFINES=============================================
#define int   long long 
#define M 1000000007 //1e9+7
#define pi 3.1415926535897932384626
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define vi vector<int>
#define input(v) for(int &c:v)cin>>c;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
#define fastio  cin.tie(0), cout.tie(0),ios_base::sync_with_stdio(false);

// pbds find_by_order, order_of_key
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; 


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//===============================================Functions=============================================

//Modular subtraction
int modsub(int a,int b,int c){ return ((a%c) - (b%c) + c)%c;}
//Modular Power
int modpow(int x,int n,int c){int result=1;while(n>0) {if(n & 1) result=(result * x)%c ; x=(x*x) % c ; n>>=1;}return result;}   //LCM
int lcm(int a, int b){return (a / __gcd(a, b)) * b;}
//Modular Inverse (x is  inverse of b under modulo m)
int modInverse(int b, int m) {return modpow(b,m-2,m);} //Fermat's little theorem if(M = prime) else extended_gcd 
//MOdular Division
 int modDivide(int a, int b, int m){a = a % m;int inv = modInverse(b, m);if (inv == -1)return -1;else return (inv * a) % m;} 

const int N = 1e5+10;
const int INF=1e9+10;


//===================================================Code Here=========================================

const int MAX = 17;
vector<vector<int>>table;
vector<int>level,parent;
void build(){
    int n = parent.size();
    table.resize(MAX,vector<int>(n,0));
    for(int i = 0;i<n;i++)table[0][i] = parent[i];

    for(int i = 1;i<MAX;i++){
        for(int j = 0;j<n;j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
}

int lca(int u, int v){
    if(level[u]>level[v])swap(u,v);

    int k = level[v]-level[u];
    
    for(int i = MAX;i>=0;i--){
        if( (k>>i)&1 ) v = table[i][v];
    }

    if(u==v)return u;

    for(int i = MAX;i>=0;i--){
        int up = table[i][u];
        int vp = table[i][v];
        if(up != vp){
            u = up;
            v = vp;
        }
    }
    return parent[u];
}

int query(int a, int k){
    for(int i = 0;i<MAX;i++){
        if( (k>>i)&1 ) a = table[i][a];
    }
    return a;
}

void sol(){
    int n;cin>>n;
    parent.resize(n);
    for(auto &c:parent)cin>>c;

    build();
    int q;cin>>q;
    while(q--){
        int a;cin>>a;
        int k;cin>>k;
        cout<<query(a,k)<<"\n";
    }

    
}

 

//===================================================Main==============================================
signed main() {
  
     fastio;
    int T=1;
    cin>>T;
   
    while(T--)
     sol();

}
