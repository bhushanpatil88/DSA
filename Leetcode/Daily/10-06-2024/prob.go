func heightChecker(h []int) int {
    nums := make([]int, len(h))
    copy(nums,h)
    sort.Ints(nums)
    cnt := 0
    for i:=0;i<len(h);i++{
        if nums[i]!=h[i]{
            cnt++
        }
    }

    return cnt
}