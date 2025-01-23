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

func printLinkedListInReverseRecursive(head InmutableListNode) {
	if head != nil {
		printLinkedListInReverseRecursive(head.getNext())
		head.printValue()
	}
}

func main() {
}
