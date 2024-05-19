func maximumValueSum(nums []int, k int, edges [][]int) int64 {
    var sum int64 = 0
    cnt := 0
    var sac int64 = 1e9
    for _,c := range nums{
        if (c^k)>c{
            sum += int64(c ^ k)
            sac = min(sac,int64((c ^ k) - c))
            cnt++
        }else{
            sum += int64(c)
            sac = min(sac,int64(c-(c^k)))
        }
    }

    if cnt%2 == 0{
        return sum
    }

    return sum - sac
}