func equalSubstring(s string, t string, maxCost int) int {
    n := len(s)
    sum := 0
    ans := 0
    l := 0
    for r:=0;r<n;r++{
        sum += abs(int(s[r])-int(t[r]))
        for sum > maxCost{
            sum -= abs(int(s[l])-int(t[l]))
            l+=1
        }

        ans = max(ans,r-l+1)
    }

    return ans
}

func abs(n int) int{
    if n>0 {return n}
    return -n
}