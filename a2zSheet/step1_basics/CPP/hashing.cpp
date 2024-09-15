#include<bits/stdc++.h>

using namespace std;

void freq(vector<int>&v){
    unordered_map<int,int>mp;
    for(auto &c:v){
        mp[c]++;
    }

    for(auto &[k,v]:mp){
        cout<<k<<":"<<v<<'\n'; 
    }
}

void high_low_freq(vector<int>&v){
    unordered_map<int,int>mp;
    int highf = 0;
    int highEle = 0;
    int lowf= 1e9;
    int lowEle = 0;
    for(auto &c:v)mp[c]++;

    for(auto &[k,v]:mp){
        if(v>highf){
            highf = v;
            highEle = k;
        }
        if(v<lowf){
            lowf = v;
            lowEle = k; 
        }
    }

    cout<<highEle<<" "<<lowEle<<'\n';

}


int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(auto &c:v)cin>>c;
    high_low_freq(v);
    return 0;
}