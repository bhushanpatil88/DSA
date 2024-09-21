#include<bits/stdc++.h>

using namespace std;

int func(int mid,int n,int m){
    int ans = 1;
    for(int i =1;i<=n;i++){
        ans *= mid;
        if(ans>m)return 2;
    }
    return (ans==m);
}

int NthRoot(int n,int m){

    int l = 1,h = m;
    while(l<=h){
        int mid = (l+h)/2;
        int midN = func(mid,n,m);
        if(midN==1)return mid;
        else if(midN==0)l = mid+1;
        else h = mid-1;
    }
    return -1;
}

int MatrixMedian(int n,int m,vector<vector<int>>v){
    int l = 1,h = 1e9;
    while(l<=h){
        int mid = (l+h)/2;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt += upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
        }
        if(cnt<=(n*m)/2)l = mid+1;
        else h= mid-1;
    }

    return l;
}   

int singleNonDuplicate(vector<int>&v){
    int n = v.size();
    if(n==1)return v[0];
    if(v[0]!=v[1])return v[0];
    if(v[n-1]!=v[n-2])return v[n-1];    
    int l = 1, h = n-2;
    while(l<=h){
        int mid = (l+h)/2;
        if(v[mid]!=v[mid-1] and v[mid]!=v[mid+1]){
            return v[mid];
        }
        if((v[mid]==v[mid-1] and mid%2==1) || (v[mid]==v[mid+1] and mid%2==0)  ){
            l = mid+1;
        }
        else{
            h= mid-1;
        }
    }

    return -1;
}
int searchRoatetdSorted(vector<int>&v,int target){
    int n = v.size();
    int l = 0, h= n-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(v[mid]==target)return mid;
        if(v[l]<=v[mid]){
            if(v[l]<=target and target<=v[mid]){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else{
            if(v[mid]<=target and target<=v[h]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
    }
    return -1;
}

int MedianTwoSortedArrays(vector<int>v1, vector<int>v2){
    int n1 = v1.size();
    int n2 = v2.size();
    if(n1>n2)MedianTwoSortedArrays(v2,v1);
    int n = (n1+n2);
    int left = (n1+n2+1)/2;
    
    // Only change for Kth element in 2 sorted arrays.
    // int left = k; 
    // int low = max(0, k - n1), high = min(k, n2);
    
    int l = 0, h = n1;
    while(l<=h){
        int mid1 = (l+h)/2;
        int mid2 = left-mid1;
        int l1 = (mid1-1>=0)?v1[mid1]:-1e9;
        int l2 = (mid2-1>=0)?v2[mid2]:-1e9;
        int r1 = (mid1<n1)?v1[mid1]:1e9;
        int r2 = (mid2<n2)?v2[mid2]:1e9;
        if(l1<=r1 and l2<=r2){
            if(n%2==1)return max(l1,l2);
            return (max(l1,l2)+min(r1,r2))/2;
        }
        else if(l1>r2){
            h = mid1-1;
        }
        else l = mid1+1;
    }
    return 0;   
}

bool isCowsValid(int mid,int cows, vector<int>&v){
    int cnt = 1;
    int prev = 0;
    for(int i = 1;i<v.size();i++){
        if(v[i]-v[prev]>=mid){
            cnt++;
            prev = i;
        }
        if(cnt>=cows)return true;
    
    }
    return cnt>=cows;
}

int AggressiveCows(vector<int>v,int cows){
    sort(v.begin(),v.end());
    int n = v.size();
    int l = 1, h = v[n-1]-v[0];
    while(l<=h){
        int mid = (l+h)/2;
        if(isCowsValid(mid,cows,v)){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return h;
}

bool isPageValid(int mid,int student, vector<int>&v){
    int cnt = 1;
    long long sum = 0;
    for(int i=0;i<v.size();i++){
        if(sum+v[i]<=mid){
            sum += v[i];
        }
        else{
            cnt++;
            sum = v[i];
        }
    }
    return cnt<=student;
}

int AllocateBooks(vector<int>&v, int students){
    int n = v.size();
    if(students>n)return -1;
    int l = *max_element(v.begin(), v.end());
    int h = accumulate(v.begin(), v.end(), 0);
    while(l<=h){
        int mid = (l+h)/2;
        if(isPageValid(mid,students,v)){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    return 0;
}