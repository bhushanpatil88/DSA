class Solution {
public:
    const int mod = 1e9+7;
    int dp[100001][3][4];
    int f(int n,int ac,int clc){
        if(n==0)return 1;
        if(dp[n][ac][clc]!=-1)return dp[n][ac][clc];
        int ans = 0;
        ans = (f(n-1,ac,0))%mod;
        if(ac<1){
            ans = (ans + f(n-1,ac+1,0))%mod;
        }
        if(clc<2){
            ans = (ans + f(n-1,ac,clc+1))% mod;
        }

        return dp[n][ac][clc] = ans%mod;

    }
    int checkRecord(int n) {
        // memset(dp,-1,sizeof dp);
        // return f(n,0,0);

        for(int ac=0;ac<=1;ac++){
            for(int clc=0;clc<=2;clc++){
                dp[0][ac][clc] = 1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int ac=0;ac<=1;ac++){
                for(int clc=0;clc<=2;clc++){
                    dp[i][ac][clc] = dp[i-1][ac][0];
                    dp[i][ac][clc] = (dp[i][ac][clc] + dp[i-1][ac+1][0])%mod;
                    dp[i][ac][clc] = (dp[i][ac][clc] + dp[i-1][ac][clc+1])%mod;
                }
             }
        }

        return dp[n][0][0]%mod;
    }
};