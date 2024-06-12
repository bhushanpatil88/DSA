func swap(a, b *int){
    temp := *b
    *b = *a
    *a = temp
}
func sortColors(v []int)  {
    l, mid, h := 0,0, len(v)-1

    for mid<=h{
        if v[mid]==0{
            v[mid],v[l] = v[l],v[mid]
            l++
            mid++
        }else if v[mid]==1{
            mid++
        }else{
            v[mid],v[h] = v[h],v[mid]
            h--
        }
    }
}