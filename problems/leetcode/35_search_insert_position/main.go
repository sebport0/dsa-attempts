// 35. Search Insert Position: https://leetcode.com/problems/search-insert-position
package main

import "fmt"

func searchInsert(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	o, l, r := binarySearch(nums, target, left, right)
	if o == -1 {
		m := (l + r) / 2
		if target > nums[m] {
			return m + 1
		}
		return m
	}
	return o
}

func binarySearch(nums []int, target, left, right int) (int, int, int) {
	for left <= right {
		middle := (left + right) / 2
		if target > nums[middle] {
			left = middle + 1
		} else if target < nums[middle] {
			right = middle - 1
		} else {
			return middle, left, right
		}
	}
	return -1, left, right
}

func searchInsertEasier(nums []int, target int) int {
	l := 0
	r := len(nums) - 1
	for l <= r {
		m := (l + r) / 2
		if target < nums[m] {
			r = m - 1
		} else if target > nums[m] {
			l = m + 1
		} else {
			return m
		}
	}
	return l
}

func main() {
	nums := []int{1, 3, 5, 6}
	t := 7
	r := searchInsertEasier(nums, t)
	fmt.Println("t =", t, "result =", r)
}
