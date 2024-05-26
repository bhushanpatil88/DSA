var dp [][3][4]int
const mod int = 1e9+7
func f(n,ac,clc int)int{
    if n==0{
        return 1
    }
    ans := 0
    if dp[n][ac][clc]!=-1{
        return dp[n][ac][clc]
    }
    ans = f(n-1,ac,0);
    if ac<1{
        ans = (ans + f(n-1,ac+1,0))%mod;
    }
    if(clc<2){
        ans = (ans + f(n-1,ac,clc+1))%mod;
    }

    dp[n][ac][clc] = ans%mod;

    return dp[n][ac][clc];
}
func checkRecord(n int) int {
    dp = make([][3][4]int,n+1)
    // for i:= range dp{
    //     dp[i] = [2][3]int{
    //         [3]int{-1,-1,-1},
    //         [3]int{-1,-1,-1},
    //     }
    // }
    // return f(n,0,0);

    for ac:=0;ac<=1;ac++{
        for clc:=0;clc<=2;clc++{
            dp[0][ac][clc] = 1;
        }
    }

    for i:=1;i<=n;i++{
        for ac:=0;ac<=1;ac++{
            for clc:=0;clc<=2;clc++{
                dp[i][ac][clc] = dp[i-1][ac][0]
                dp[i][ac][clc] = (dp[i][ac][clc] + dp[i-1][ac+1][0])%mod; 
                dp[i][ac][clc] = (dp[i][ac][clc] + dp[i-1][ac][clc+1])%mod;
            }
        }
    }

    return dp[n][0][0];
}