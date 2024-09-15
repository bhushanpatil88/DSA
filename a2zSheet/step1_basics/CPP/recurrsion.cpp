#include<bits/stdc++.h>

using namespace std;

void printName(int n){
    if(n==0)return;
    cout<<"Bhushan\n";
    printName(n-1);
}

void printNums_12N(int n){
    if(n==0)return;
    printNums_12N(n-1);
    cout<<n<<" ";
}

void printNums_N21(int n){
    if(n==0)return;
    cout<<n<<" ";
    printNums_N21(n-1);
}

int sum(int n){
    if(n==0)return 0;
    return n + sum(n-1);
}

int fact(int n){
    if(n==0)return 1;
    return n*fact(n-1);
}

void reverseArray(vector<int>&v,int start,int end){
    if(start>=end)return;
    swap(v[end],v[start]);
    reverseArray(v,start+1,end-1);
}

bool isPal(string &s, int start,int end){
    if(start>=end)return true;
    return s[start]==s[end] && isPal(s,start+1,end-1);
}

void fib(int a,int b,int n){
    if(n==0)return;
    int c = a+b;
    a = b;
    b = c;
    cout<<c<<" ";
    fib(a,b,n-1);

}


int main(){
    int n;cin>>n;
    // vector<int>v(n);
    // for(auto &c:v)cin>>c;
    // reverseArray(v,0,n-1);
    // for(auto &c:v)cout<<c<<" ";
    cout<<"0 1 ";
    fib(0,1,n-2);
    return 0;
}