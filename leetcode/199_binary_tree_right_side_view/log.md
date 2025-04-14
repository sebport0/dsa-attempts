# 199.Binary Tree Right Side View

[Link](https://leetcode.com/problems/binary-tree-right-side-view)

- Complexity

  - Time: $O(n)$, we go from node to node in the tree.

  - Space: $O(n)$, a queue must be maintained with the nodes of the tree.

First, we can use BFS to solve this problem because the comparison of what nodes to add
the answer is done level by level. BFS is a perfect match for it!

Second, the trick is to be aware of the order in which the nodes are added to the queue.
If add the left node first and the right node at last, then we'll be looking at "the
right-most node" at the end of each level.
