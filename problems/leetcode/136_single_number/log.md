# 136. Single Number

[Link](https://leetcode.com/problems/single-number/)

- Constraint: you must implement a solution with a linear runtime complexity and use only
  constant extra space.

  - This is easy if the properties of the XOR operation are known

    - $x \oplus 0 = x$

    - $x \oplus x = 0$

    - XOR is conmutative and associative: $x \oplus y \oplus x = (x \oplus x) \oplus y = y$
