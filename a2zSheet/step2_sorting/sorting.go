package main

import (
	"bufio"
	. "fmt"
	. "math"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func swap(a, b *int) {
	temp := *a
	*a = *b
	*b = temp
}

func SelectionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		mini := MaxInt32
		min_ind := -1
		for j := i; j < len(arr); j++ {
			if mini > arr[j] {
				mini = arr[j]
				min_ind = j
			}
		}
		swap(&arr[i], &arr[min_ind])
	}

	Print(arr)
}

func BubbleSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-i-1; j++ {
			if arr[j] > arr[j+1] {
				swap(&arr[j], &arr[j+1])
			}

		}
	}
	Print(arr)
}

func InsertionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := i; j > 0; j-- {
			if arr[j] < arr[j-1] {
				swap(&arr[j], &arr[j-1])
			}
		}
	}
	Print(arr)
}

func Merge(start, mid, end int, arr []int) {
	temp := make([]int, end-start+1)
	l, r := start, mid+1

	k := 0
	for l <= mid && r <= end {
		if arr[l] <= arr[r] {
			temp[k] = arr[l]
			l++
		} else {
			temp[k] = arr[r]
			r++
		}

		k++
	}
	for l <= mid {
		temp[k] = arr[l]
		l++
		k++
	}
	for r <= end {
		temp[k] = arr[r]
		r++
		k++
	}

	for i := start; i <= end; i++ {
		arr[i] = temp[i-start]
	}
}
func MergeSort(start, end int, arr []int) {
	if start >= end {
		return
	}
	mid := (start + end) / 2
	MergeSort(start, mid, arr)
	MergeSort(mid+1, end, arr)
	Merge(start, mid, end, arr)
}

func Partition(arr []int, start, end int) int {
	pivot := arr[start]
	l, r := start, end

	for l < r {
		for arr[l] <= pivot && l < end {
			l++
		}
		for arr[r] > pivot && r > start {
			r--
		}
		if l < r {
			swap(&arr[l], &arr[r])
		}
	}
	swap(&arr[start], &arr[r])

	return r
}

func QuickSort(arr []int, start, end int) {
	if start >= end {
		return
	}
	pivot := Partition(arr, start, end)
	QuickSort(arr, start, pivot-1)
	QuickSort(arr, pivot+1, end)
}

func solve() {
	var n int
	Fscan(in, &n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &arr[i])
	}
	QuickSort(arr, 0, n-1)

	Print(arr)
}

func main() {
	var t int
	for Fscan(in, &t); t > 0; t-- {
		solve()
	}
}
