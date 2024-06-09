package main

import (
	"fmt"
)

type Node struct {
	links  [26]*Node
	isLeaf bool
}

type Trie struct {
	root *Node
}

func Constructor() Trie {
	return Trie{root: &Node{}}
}

func (t *Trie) Insert(word string) {
	temp := t.root
	for _, c := range word {
		index := c - 'a'
		if temp.links[index] == nil {
			temp.links[index] = &Node{}
		}
		temp = temp.links[index]
	}
	temp.isLeaf = true
}

func (t *Trie) CountPrefixs(word string) int {
	temp := t.root
	cnt := 0
	for _, c := range word {
		if temp.links[c-'a'] != nil {
			temp = temp.links[c-'a']
			if temp.isLeaf {
				cnt++
			}
		} else {
			return 0
		}
	}
	return cnt
}

func completeString(n int, a []string) string {
	t := Constructor()
	for _, str := range a {
		t.Insert(str)
	}

	ans := ""
	gcnt := 0
	for _, str := range a {
		cnt := t.CountPrefixs(str)
		if cnt != len(str) {
			continue
		}
		if cnt > gcnt {
			ans = str
			gcnt = cnt
		} else if cnt == gcnt {
			if str < ans {
				ans = str
			}
		}
	}

	if ans == "" {
		return "None"
	}
	return ans
}

func main() {
	a := []string{"n", "ni", "nin", "ninj", "ninja", "ninga"}
	n := len(a)
	fmt.Println(completeString(n, a))
}
