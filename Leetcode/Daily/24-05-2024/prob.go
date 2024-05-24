var a,b [26]int
var ans int

func f(ind int,words []string,score []int){
    if ind==len(words){
        sum := 0
        for i:=0;i<26;i++{
            if b[i]>a[i]{
                return
            }

            sum += score[i]*b[i]
        }
        ans = max(ans, sum)
        return
    }
    // fmt.Println(ind)
    for _,c := range words[ind]{
        b[c-'a']++
    }
    f(ind+1,words,score)
    for _,c := range words[ind]{
        b[c-'a']--
    }

    f(ind+1,words,score)
}

func maxScoreWords(words []string, letters []byte, score []int) int {
    ans = 0
	for i := range a {
		a[i] = 0
		b[i] = 0
	}

	for _, c := range letters {
		a[c-'a']++
	}

    f(0,words,score)

    return ans
}