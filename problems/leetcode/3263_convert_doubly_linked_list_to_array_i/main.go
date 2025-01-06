// 3263. Convert Doubly Linked List to Array I: https://leetcode.com/problems/convert-doubly-linked-list-to-array-i
package main

type Node struct {
	Val  int
	Next *Node
	Prev *Node
}

func toArray(head *Node) []int {
	curr := head
	arr := []int{}
	for curr != nil {
		arr = append(arr, curr.Val)
		curr = curr.Next
	}
	return arr
}

func main() {
}
