func countTriplets(arr []int) int {
    ans := 0
    n := len(arr)
    for i, val := range arr{
        for k := i + 1; k < n; k++{
            val ^= arr[k]
            if val == 0{
                ans += k - i
            }
        }
    }
    return ans
}