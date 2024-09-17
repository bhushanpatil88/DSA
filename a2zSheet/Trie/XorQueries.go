package main

import (
	"sort"
)

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

type ds struct {
	x   int
	m   int
	ind int
}

func maximizeXor(nums []int, queries [][]int) []int {

	sort.Ints(nums)

	Q := make([]ds, len(queries))
	for i, q := range queries {
		Q[i] = ds{q[0], q[1], i}
	}

	sort.Slice(Q, func(i, j int) bool {
		return Q[i].m < Q[j].m
	})

	// fmt.Print(Q)
	ans := make([]int, len(queries))
	n := len(nums)
	ind := 0

	t := Constructor()

	for _, c := range Q {
		x := c.x
		m := c.m
		qInd := c.ind

		for ind < n && nums[ind] <= m {
			t.Insert(nums[ind])
			ind++
		}
		if ind == 0 {
			ans[qInd] = -1
		} else {
			ans[qInd] = t.GetMax(x)
		}
	}
	return ans

}
