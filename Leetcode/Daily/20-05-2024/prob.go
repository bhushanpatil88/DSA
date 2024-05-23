func subsetXORSum(nums []int) int {

    sum := 0
    l := len(nums)
    for i:=1;i<(1<<l);i++{
        x := 0
        for j:=0;j<len(nums);j++{
            if (i>>j)&1 == 1 {
                x = (x^nums[j])
            }
        }
        sum += x
    }

    return sum
}