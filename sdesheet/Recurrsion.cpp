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

int main()
{
    int n;cin>>n;
    v.resize(n);
    for(auto &c:v)cin>>c;
    return 0;
}