func longestPalindrome(s string) int {
    mp := make(map[rune]int)

    for _,c := range s{
        mp[c]++
    }
    cnt := 0
    odd := 0
    for _,k := range mp{
        if k%2==0{
            cnt += k
        }else{
          
            cnt += k-1
            odd = 1
            
        }
    }
    if odd==1{
        cnt++
    }
    return cnt
}