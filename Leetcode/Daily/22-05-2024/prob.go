func isPal(s string, start int,end int) bool{
    for start<=end{
            if(s[start]!=s[end]){
                return false
            }
            start++
            end--
        }

        return true
}

func f(ind int,s string,ans *[][]string,v *[]string){
    if ind==len(s) {
            temp := make([]string, len(*v))
            copy(temp, *v)
            *ans = append(*ans, temp)
            return
    }
    for i:=ind;i<len(s);i++{
        if !isPal(s,ind,i) {
            continue
        }
        *v = append(*v,s[ind:i+1])
        f(i+1,s,ans,v)
        *v = (*v)[:len(*v)-1]
    }
}

func partition(s string) [][]string {
    var ans [][]string
    var v []string
    ind := 0

    f(ind,s,&ans,&v)

    return ans
}