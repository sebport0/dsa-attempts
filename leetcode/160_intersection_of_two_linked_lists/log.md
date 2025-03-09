# 160. Intersection of Two Linked Lists

[Link](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

- V1 Set solution:

  - Time: $O(n+m)$ where $n$ is the length of list A and $m$ is the length of list B.
    At most, both lists must be fully iterated to get a solution.

  - Space: $O(n+m)$, the set -at most- must store the the nodes of list A and the nodes
    of list B.

- V2 Pointers solution:

  - Time: $O(n+m)$ same as V1.

  - Space: $O(1)$ because there are no additional data structures to hold in memory.
