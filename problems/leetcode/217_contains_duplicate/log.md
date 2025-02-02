# 217. Contains Duplicate

[Link](https://leetcode.com/problems/contains-duplicate)

- Sort solution

  - Complexity

    - Time: $O(nlogn)$, because in C++ sort is $O(nlogn)$ which is greater
      than the $O(n)$ iteration of the for loop.

    - Space: $O(1)$, nums is sorted and walked in place.

- Set solution

  - Complexity

    - Time: $O(nlogn)$, according to [set::find](https://en.cppreference.com/w/cpp/container/set/find)
      find is log worst case.

    - Space: $O(n)$, there is a set to maintain in memory that, at worst, have the same
      elements of the vector.
