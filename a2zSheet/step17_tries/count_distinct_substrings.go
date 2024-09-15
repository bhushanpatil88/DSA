package main

import "fmt"

type Node struct {
	links [26]*Node
}

func countDistinctSubstrings(s string) int {
	n := len(s)
	root := &Node{}
	cnt := 0
	for i := 0; i < n; i++ {
		temp := root
		for j := i; j < n; j++ {
			if temp.links[s[j]-'a'] == nil {
				cnt++
				temp.links[s[j]-'a'] = &Node{}
			}
			temp = temp.links[s[j]-'a']
		}
	}

	return cnt + 1
}

func main() {
	s := "abc"
	fmt.Print(countDistinctSubstrings(s))
}
