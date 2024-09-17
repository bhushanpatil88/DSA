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

func (t *Trie) Search(word string) bool {
	temp := t.root
	for _, c := range word {
		index := c - 'a'
		if temp.links[index] == nil {
			return false
		}
		temp = temp.links[index]
	}
	return temp.isLeaf
}

func (t *Trie) StartsWith(prefix string) bool {
	temp := t.root
	for _, c := range prefix {
		index := c - 'a'
		if temp.links[index] == nil {
			return false
		}
		temp = temp.links[index]
	}
	return true
}
