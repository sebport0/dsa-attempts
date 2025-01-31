# 141. Linked List Cycle

- `set.insert()` returns a pair where the second value is a boolean indicating if the value
  was inserted or not.

- Iterative solution

  - Time: $O(n)$, because all nodes must be walked.

  - Space: $O(n)$, because -at worst- the linked list doesn't have a cycle.

- Floyd Algorithm Solution

  - Time: $O(n)$, at worst the cycle points to the first node in the list.

  - Space: $O(1)$, we are using pointers and no extra data structure.
