package main

import (
	"bufio"
	. "fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func PrintName(n int) {
	if n == 0 {
		return
	}
	Fprint(out, "Bhushan\n")
	PrintName(n - 1)
}

func PrintNums_12N(n int) {
	if n == 0 {
		return
	}
	PrintNums_12N(n - 1)
	Print(n, " ")
}

func PrintNums_N21(n int) {
	if n == 0 {
		return
	}
	Fprintln(out, n)
	PrintNums_N21(n - 1)
}

func Sum(n int) int {
	if n == 0 {
		return 0
	}

	return n + Sum(n-1)
}

func Fact(n int) int {
	if n == 0 {
		return 1
	}

	return n * Fact(n-1)
}

func ReverseArr(arr []int, start int, end int) {
	if start >= end {
		return
	}
	var temp = arr[start]
	arr[start] = arr[end]
	arr[end] = temp
	ReverseArr(arr, start+1, end-1)
}

func IsPal(s string, start int, end int) bool {
	if start >= end {
		return true
	}

	return (s[start] == s[end] && IsPal(s, start+1, end-1))
}

func Fib(n int, a int, b int, counter int) {
	if n == counter {
		return
	}
	c := a + b
	a = b
	b = c
	Fprint(out, c, " ")
	Fib(n, a, b, counter+1)
}

func solve() {
	var n int
	Fscan(in, &n)
	// arr := make([]int, n)
	// for i := 0; i < n; i++ {
	// 	Fscan(in, &arr[i])
	// }
	// var s string
	// Fscan(in, &s)
	Fprint(out, "0 1 ")
	Fib(n, 0, 1, 1)

}

func main() {
	defer out.Flush()
	var t int

	for Fscan(in, &t); t > 0; t-- {
		solve()
	}
}
