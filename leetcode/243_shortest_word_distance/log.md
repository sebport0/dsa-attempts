# 243. Shortest Word Distance

[Link](https://leetcode.com/problems/shortest-word-distance)

- word1 and word1 can be repeated. The shortest distance must be returned. It's possible
  to have more than one distance value. For example: `["a", "a", "b", "b"]`.

- Complexity

  - Time: $O(n)$ because the entire array must be walked to make sure the `minimum`
    distance is calculated.

  - Space: $O(1)$, there are no extra data structures to hold on memory.

- It could be solved in $O(n^2) by matching word1 and then iterating over the
  entire array looking for word2 to calculate the minimum distance.
