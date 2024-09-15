type Node struct {
	links [26]*Node
	pref  int
	ends  int
}

type Trie struct {
	root *Node
}

func Constructor() Trie {
	return Trie{root: &Node{}}
}

func (t *Trie) insert(word string) {
	temp := t.root
	for _, c := range word {
		if temp.links[c-'a'] == nil {
			temp.links[c-'a'] = &Node{}
		}
		temp = temp.links[c-'a']
		temp.pref++
	}
	temp.ends++
}

func (t *Trie) countWordsEqualTo(word string) int {
	temp := t.root
	for _, c := range word {
		if temp.links[c-'a'] != nil {
			temp = temp.links[c-'a']
		} else {
			return 0
		}
	}
	return temp.ends
}

func (t *Trie) countWordsStartingWith(word string) int {
	temp := t.root
	for _, c := range word {
		if temp.links[c-'a'] != nil {
			temp = temp.links[c-'a']
		} else {
			return 0
		}
	}
	return temp.pref
}

func (t *Trie) erase(word string) {
	temp := t.root
	for _, c := range word {
		if temp.links[c-'a'] != nil {
			temp = temp.links[c-'a']
			temp.pref--
		}
	}
	temp.ends--
}
