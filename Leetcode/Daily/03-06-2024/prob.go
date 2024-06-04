func appendCharacters(s string, t string) int {
    i := 0
    j := 0

    for i<len(s) && j<len(t){
        if s[i]==t[j]{
            i++
            j++
        }else {
            i++
        }
    }

    return len(t)-j
}