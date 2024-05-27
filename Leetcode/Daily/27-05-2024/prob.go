func lower_bound(arr []int, ele int)int{
    l,r := 0,len(arr)

    for l<r{
        mid := (l+r)/2
        if arr[mid]>=ele{
            r = mid
        }else{
            l = mid+1
        }
    }

    return l
}

func specialArray(nums []int) int {
    sort.Ints(nums)
    n := len(nums)
    maxi := nums[n-1]
    for i:=1;i<=maxi;i++{
        lb := lower_bound(nums,i)
        if n-lb == i{
            return i
        }
    }

    return -1
}