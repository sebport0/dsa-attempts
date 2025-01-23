// 1265. Print Immutable Linked List in Reverse: https://leetcode.com/problems/print-immutable-linked-list-in-reverse
package main

/*   Below is the interface for ImmutableListNode, which is already defined for you.
 *
 *   type ImmutableListNode struct {
 *
 *   }
 *
 *   func (this *ImmutableListNode) getNext() ImmutableListNode {
 *		// return the next node.
 *   }
 *
 *   func (this *ImmutableListNode) printValue() {
 *		// print the value of this node.
 *   }
 */

func printLinkedListInReverse(head ImmutableListNode) {
	for head != nil {
		// defer works as a stack. LIFO.
		defer head.printValue()
		head = head.getNext()
	}
}

func printLinkedListInReverseRecursive(head ImmutableListNode) {
	if head != nil {
		printLinkedListInReverseRecursive(head.getNext())
		head.printValue()
	}
}

func printLinkedListInReverseStack(head ImmutableListNode) {
	stack := []ImmutableListNode{}
	for head != nil {
		stack = append(stack, head)
		head = head.getNext()
	}
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		node.printValue()
		stack = stack[:len(stack)-1]
	}
}

func main() {
}
