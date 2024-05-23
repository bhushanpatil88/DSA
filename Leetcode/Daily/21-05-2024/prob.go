func subsets(nums []int) [][]int {
    var ans [][]int

    sz := len(nums)

    for i:=0;i<(1<<sz);i++{
        var v []int
        for j:=0;j<sz;j++{
            if (i>>j)&1 == 1{
                v = append(v,nums[j])
            }
        }
        ans = append(ans,v)
    }

    return ans
}