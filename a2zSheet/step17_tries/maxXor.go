package main

type Node struct {
	links [2]*Node
}

type Trie struct {
	root *Node
}

func Constructor() Trie {
	return Trie{root: &Node{}}
}

func (t *Trie) Insert(num int) {
	temp := t.root
	for i := 31; i >= 0; i-- {
		bit := (num >> i) & 1
		if temp.links[bit] == nil {
			temp.links[bit] = &Node{}
		}
		temp = temp.links[bit]
	}
}

func (t *Trie) GetMax(num int) int {
	temp := t.root
	maxi := 0
	for i := 31; i >= 0; i-- {
		bit := ((num >> i) & 1)
		if temp.links[1-bit] != nil {
			maxi |= (1 << i)
			temp = temp.links[1-bit]
		} else {
			temp = temp.links[bit]
		}
	}

	return maxi
}
