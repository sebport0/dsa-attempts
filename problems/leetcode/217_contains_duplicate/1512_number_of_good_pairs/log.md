# 1512. Number of Good Pairs

[Link](https://leetcode.com/problems/number-of-good-pairs)

- Double for loop Solution

  - Complexity

    - Time: $O(n^2)$

    - Space: $O(1)$

- Hash Map solution

  - Complexity

    - Time: $O(n)$

    - Space: $O(n)$

    - The key here is that the question only asks for the number of good pairs and
      not to list them.

    - Iterate over `nums`, each num -at first- adds 0. This looks like a waste at
      first but it's what make it works.
