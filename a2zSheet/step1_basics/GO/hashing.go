package main

import (
	"bufio"
	. "fmt"
	"math"
	"os"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func freq(arr []int) {
	mp := make(map[int]int)
	for _, ele := range arr {
		mp[ele]++
	}
	for k, v := range mp {
		Println(k, " : ", v)
	}

}

func high_low_freq(arr []int) {
	mp := make(map[int]int)
	highf := 0
	highEle := 0
	lowf := math.MaxInt32
	lowEle := 0
	for _, ele := range arr {
		mp[ele]++
	}

	for k, v := range mp {
		if v > highf {
			highEle = k
			highf = v
		}
		if v < lowf {
			lowEle = k
			lowf = v
		}
	}

	Print(highEle, " : ", lowEle)
}

func solve() {
	var n int
	Fscan(in, &n)
	arr := make([]int, n)

	for i := 0; i < n; i++ {
		Fscan(in, &arr[i])
	}
	// freq(arr)
	high_low_freq(arr)

}

func main() {
	defer out.Flush()
	var t int
	for Fscan(in, &t); t > 0; t-- {
		solve()
	}
}
