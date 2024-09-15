package main

import (
	"bufio"
	. "fmt"
	. "math"
	"os"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func CountDigits(n int) int {
	if n == 0 {
		return 1
	}
	return int(Log10(float64(n)) + 1)
}

func ReverseNumber(n int) int {
	newNum := 0
	for n > 0 {
		rem := n % 10
		n /= 10
		newNum = newNum*10 + rem
	}

	return newNum
}

func IsPalNum(n int) bool {
	reversed := ReverseNumber(n)

	return n == reversed
}
func Gcd(a, b int) int {
	for a > 0 && b > 0 {
		if a > b {
			a %= b
		} else {
			b %= a
		}
	}
	if a == 0 {
		return b
	}
	return a
}

func IsArmstrong(n int) bool {
	temp := n
	newNum := 0
	for n > 0 {
		rem := n % 10
		n = n / 10
		newNum += int(Pow(float64(rem), 3))
	}
	return newNum == temp
}

func Divisors(n int) []int {
	var divisors []int

	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			divisors = append(divisors, i)
			if n/i != i {
				divisors = append(divisors, n/i)
			}
		}
	}
	return divisors
}

func IsPrime(n int) bool {

	for i := 2; i*i < n; i++ {
		if n%i == 0 {
			return false
		}
	}

	return true
}

func solve() {
	var n int
	Fscan(in, &n)
	// Print(CountDigits(n), "\n")
	// Print(IsPalNum(n), "\n")
	// Print(Gcd(10, 15), "\n")
	// Print(IsArmstrong(153), "\n")
	Print(IsPrime(n), "\n")

}

func main() {
	defer out.Flush()
	var Test int
	Fscanf(in, "%d\n", &Test)
	for tt := 0; tt < Test; tt++ {
		solve()
	}
}
