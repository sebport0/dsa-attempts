// 230. Kth Smallest Element in a BST: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var l []int

func traverse(root *TreeNode, l []int) []int {
	if root != nil {
		l = traverse(root.Left, l)
		l = append(l, root.Val)
		l = traverse(root.Right, l)
	}
	return l
}

func kthSmallest(root *TreeNode, k int) int {
	return traverse(root, l)[k-1]
}

func main() {
	tree := &TreeNode{
		Val:   3,
		Left:  &TreeNode{Val: 1, Right: &TreeNode{Val: 2}},
		Right: &TreeNode{Val: 4},
	}
	out := kthSmallest(tree, 1)
	fmt.Printf("out=%+v\n", out)
	tree2 := &TreeNode{
		Val:   5,
		Left:  &TreeNode{Val: 3, Left: &TreeNode{Val: 2, Left: &TreeNode{Val: 1}}, Right: &TreeNode{Val: 4}},
		Right: &TreeNode{Val: 6},
	}
	out2 := kthSmallest(tree2, 3)
	fmt.Printf("out=%+v\n", out2)
}
