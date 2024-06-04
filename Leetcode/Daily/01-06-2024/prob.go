func abs(a int) int {
    if a < 0 {
        return -1 * a
    }
    return a
}
func scoreOfString(s string) int {
    n := len(s)
    ans := 0
    for i:=0;i<n-1;i++{
        ans += abs(int(s[i])-int(s[i+1]));
    }

    return ans;
}