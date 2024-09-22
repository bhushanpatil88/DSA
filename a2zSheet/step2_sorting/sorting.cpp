#include<bits/stdc++.h>
using namespace std;

// Best Case O(N)
void BubbleSort(vector<int>&v){
    int n = v.size();
   
    for(int i = 0;i<n;i++){
        bool swapped = false;
        for(int j = 0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void SelectionSort(vector<int>&v){
    int n = v.size();
    for(int i = 0;i<n;i++){
        int mini = v[i];
        int min_ind = i;
        for(int j = i+1;j<n;j++){
            if(mini>v[j]){
                mini = v[j];
                min_ind = j;
            }
        }
        swap(v[min_ind],v[i]);
    }
}

// Best Case O(N)
void InsertionSort(vector<int>&v){
    int n = v.size();
    for(int i = 0;i<n;i++){
        int j = i;
        while (j > 0 && v[j - 1] > v[j]) {
            swap(v[j-1],v[j]);
            j--;
        }
    }
}

void merger(int l,int mid,int h,vector<int>&v){
    int left = l;
    int right = mid+1;
    vector<int>temp;
    while(left<=mid and right<=h){
        if(v[left]<=v[right])temp.push_back(v[left++]);
        else{
            temp.push_back(v[right++]);
        }
    }
    while(left<=mid)temp.push_back(v[left++]);
    while(right<=h)temp.push_back(v[right++]);

    for(int i = l;i<=h;i++){
        v[i] = temp[i-l];
    }
}

// O(nlog(n)) in all the cases
void mergeSort(int l,int h,vector<int>&v){
    if(l>=h)return;
    int mid = (l+h)/2;
    mergeSort(0,mid,v);
    mergeSort(mid+1,h,v);
    merger(l,mid,h,v);
}

int Partition(int l,int h,vector<int>&v){
    int pivot = l;
    int i = l,j = h;
    while(i<j){
        while(i<=h-1 and v[i]<=v[pivot])i++;
        while(j>=l+1 and v[j]>=v[pivot])j--;
        if(i<j)swap(v[i],v[j]);
    }
    swap(v[j],v[pivot]);
    return j;
}

/*
Variation	Time Complexity	Space Complexity
Best Case	  O(n log n)	O(log n)
Average Case  O(n log n)	O(log n)
Worst Case	  O(n^2)	    O(n)  Reverse Array is provided.

*/

void QuickSort(int l,int h,vector<int>&v){
    if(l>=h)return;
    int pivot = Partition(l,h,v);
    QuickSort(l,pivot-1,v);
    QuickSort(pivot+1,h,v);
}


int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(auto &c:v)cin>>c;
    SelectionSort(v);
    for(auto &c:v)cout<<c<<" ";
    cout<<'\n';
    return 0;
}