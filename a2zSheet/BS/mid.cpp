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

int func(int mid,int n,int m){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans *=mid;
        if(ans>m)return 2;
    }
    if(ans==m)return 1;
    return 0;
}

int NthRoot(int n, int m){
    int l = 1,h = n;
    while(l<=h){
        int mid = (l+h)/2;
        int val = func(mid,n,m);
        if(val){
            return mid;
        }
        else if(val==0){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }

    return -1;
}

int calcBanana(int mid,vector<int>&v,int K){
    int ans = 0;
    for(int i=0;i<v.size();i++){
        ans += (v[i]+mid-1)/mid;
    }

    return K>=ans;
}

int KokoBanana(vector<int>&v, int K){
    int n = v.size();
    int l = 1,h=*max_element(v.begin(),v.end());
    while(l<=h){
        int mid = (l+h)/2;
        if(calcBanana(mid,v,K)){
            h = mid-1;
        }
        else l = mid+1;
    }
    return l;
}

int calcRoses(int mid,vector<int>&v,int k,int m){
    int ans = 0,prev = -1,rose=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<=mid){
            rose++;
        }
        else{
            ans += (rose/k);
            rose=0;
        }
    }
    ans += (rose/k);

    return ans>=m;
}

int roseGarden(vector<int>&v,int k,int m){
    int n = v.size();
    int val = m*k;
    if(val>n)return -1;// impossible
    int l = *min_element(all(v));
    int h = *max_element(all(v));

    while(l<=h){
        int mid = (l+h)/2;
        if(calcRoses(mid,v,k,m)){
            h = mid-1;
        } 
        else{
            l = mid+1;
        }
    }
    // whom to return low or high depends on the solution range if it is (nnnnyyyyy) return low else return high
    return l;
}

int KthMissing(vector<int>&v,int k){
    int l = 0,h = v.size()-1;
    while(l<=h){
        int mid = (l+h)/2;
        int missing = v[mid] - (mid+1);
        if(missing<k)l = mid+1;
        else h = mid-1;
    }
    return k + h + 1;
}

int calcCows(int mid,int k,vector<int>&v){
    int cnt = 1;
    int prev = v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]-prev>=mid){
            cnt++;
            prev = v[i];
        }
        if(cnt>=k)return 1;
    }

    return 0;
}
int Cows(vector<int>&v,int k){
    int n = v.size();
    sort(all(v));

    int l = 1,h = v[n-1]-v[0];
    while(l<=h){
        int mid = (l+h)/2;
        if(calcCows(mid,k,v)){
            l = mid+1;
        }
        else h = mid-1;
    }

    return h;
}

int cntStuds(vector<int>&v,int mid){
    int cnt = 1;
    int val = v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]+val>mid){
            cnt++;
            val = v[i];
        }
        else{
            val += v[i];
        }
    }
    return cnt;
}

int findPages(vector<int>&v,int m){
    int n = v.size();
    if (m > n) return -1;

    int l = *max_element(v.begin(), v.end());
    int h = accumulate(v.begin(), v.end(), 0ll);
    while (l <= h) {
        int mid = (l + h) / 2;
        int students = cntStuds(v, mid);
        if (students > m) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return l;
}

void sol(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int>v(n);
    input(v);
    cout<<findPages(v,k);    

    
}

 

//===================================================Main==============================================
signed main() {
  
     fastio;
    int T=1;
    cin>>T;
   
    while(T--)
     sol();

}
