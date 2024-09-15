#include<bits/stdc++.h>

using namespace std;


int countDigits(int n){
    if(n==0)return 1;
    return (int)(log10(n)+1);
}

int reverseNumber(int n){
    int num = 0;
    while(n>0){
        num = num*10 + n%10;
        n /= 10;
    }

    return num;
}

int isPal(int n){
    int num = reverseNumber(n);
    return num==n;
}

int gcd(int a,int b){
    while(a>0 and b>0){
        if(a>b)a %= b;
        else b %= a;
    }
    if(a==0)return b;
    return a;
}

int isArmStrong(int n){
    int num = 0;
    int temp = n;
    while(n>0){
        num += (n%10)*(n%10)*(n%10);
        n /= 10;
    }
    return num == temp;
    
}

vector<int> divisors(int n){
    vector<int>ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            if(n/i != i)ans.push_back(n/i);
        }
    }
    return ans;
}

bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


int main(){
    int n;cin>>n;
    // cout<<countDigits(n);
    // cout<<reverseNumber(n);
    cout<<isArmStrong(n);

    return 0;
}