func numSteps(s string) int {
    n := len(s)
    ans := n-1
    c := 0
    for i:=n-1;i>0;i--{
        if int(s[i]-'0') + c == 1{
            ans++
            c = 1
        }
    }

    return ans + c

}