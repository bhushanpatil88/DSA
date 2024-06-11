func relativeSortArray(arr1 []int, arr2 []int) []int {
    mp := make(map[int]int)
    for _,i:=range arr1{
        mp[i]++
    }

    var ans []int
    for _,c := range arr2{
        if count, exists := mp[c]; exists {
			for count > 0 {
				ans = append(ans, c)
				count--
			}
			mp[c] = 0 
		}
    }

    var rems []int
	for num, count := range mp {
		for count > 0 {
			rems = append(rems, num)
			count--
		}
	}

	sort.Ints(rems)
	ans = append(ans, rems...)
    return ans
}