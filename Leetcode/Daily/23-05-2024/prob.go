func f(ind int,nums []int,k int, mp map[int]int) int{
    if len(nums)==ind{
        return 1
    }
    t := 0
    if mp[nums[ind]-k]==0 && mp[nums[ind]+k]==0{
        mp[nums[ind]]++
        t = f(ind+1,nums,k,mp)
        mp[nums[ind]]--
    }

    nt := f(ind+1,nums,k,mp)
    return t+nt
}


func beautifulSubsets(nums []int, k int) int {
    mp := make(map[int]int)
    cnt := f(0,nums,k,mp)
    return cnt-1
}