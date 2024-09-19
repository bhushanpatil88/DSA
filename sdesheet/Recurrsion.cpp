#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n;cin>>n;
    // v.resize(n);
    // for(auto &c:v)cin>>c;
    // vector<int>ds;
    // sort(v.begin(),v.end());
    // combinationSum2(0,7,ds);
    // for(auto &c:ans){
    //     cout<<c<<" ";
    // }
    string s;
    cin>>s;
    vector<string>ds;
    palindromicPartition(0,s,ds);

    for(auto &c:pals){
        for(auto &d:c){
            cout<<d<<" ";
        }
        cout<<'\n';
    }
    return 0;
}