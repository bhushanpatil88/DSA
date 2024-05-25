var (
    mp map[string]bool
    ans []string
)


func f(ind int, s string, ds []string) {
	if ind == len(s) {
		ans = append(ans, strings.Join(ds, " "))
		return
	}
	for j := ind; j < len(s); j++ {
		ss := s[ind : j+1]
		if mp[ss] {
			f(j+1, s, append(ds, ss))
		}
	}
}

func wordBreak(s string, wordDict []string) []string {
    mp = make(map[string]bool)
    ans = []string{}
    for _,c := range wordDict{
        mp[c] = true
    }
    f(0,s,[]string{})

    return ans
}