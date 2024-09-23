#include<bits/stdc++.h>

using namespace std;

int KthSmallest(vector<int>&v,int k){
    int n  = v.size();
    priority_queue<int>pq;
    for(auto &c:v){
        pq.push(c);
        if(pq.size()>k){
            pq.pop();
        }
    }

    return pq.top();
}

int KthLargest(vector<int>&v, int k){
    int n = v.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto &c:v){
        pq.push(c);
        if(pq.size()>k)pq.pop();
    }
    return pq.top();
}

/*
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.
*/
struct tup{
    int sum;
    int i;
    int j;
    bool operator<(const tup& other) const {
        return sum < other.sum;
    }
};
vector<int> MaximumCombinationSum(vector<int>&A,vector<int>&B,int k){
    int n1 = A.size();
    int n2 = B.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<tup>pq;
    tup t = {A[n1-1]+B[n2-1],n1-1,n2-1};
    pq.push(t);
    set<pair<int,int>>st;
    vector<int>ans;
    st.insert({n1-1,n2-1});
    while(k--){
        tup t = pq.top();
        pq.pop();
    
        ans.push_back(t.sum);
        if(t.i-1>=0){
            if(st.find({t.i-1,t.j})==st.end()){
                st.insert({t.i-1,t.j});
                tup tt = {A[t.i-1] + B[t.j],t.i-1,t.j};
                pq.push(tt);
            }
        }
        if(t.j-1>=0){
            if(st.find({t.i,t.j-1})==st.end()){
                st.insert({t.i,t.j-1});
                tup tt = {A[t.i] + B[t.j-1],t.i,t.j-1};
                pq.push(tt);
            }
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(auto &c:v)cin>>c;
    vector<int>A = {1,2,3},B = {4,5,6};
    vector<int>ans = MaximumCombinationSum(A,B,3);
    for(auto &c:ans)cout<<c<<" ";
    return 0;
}