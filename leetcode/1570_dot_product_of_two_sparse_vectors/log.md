# 1570. Dot Product of Two Sparse Vectors

[Link](https://leetcode.com/problems/dot-product-of-two-sparse-vectors)

## Linear

"Linear" because this linear solution doesn't make use of the fact that the
vectors are sparse, so there are a lot of multiplications that could be
avoided.

- Complexity

  - Space: $O(1)$ because the sparse vector class holds the reference to
    another vector.

  - Time: $O(n)$, the dot product needs to iterate over the vectors size
    to compute the final result.

## Hash

Using a hash map is possible to make the most of the sparse condition of
the vector. We'll store only the indexes, as keys, and the elements, as values,
of the vector that are not 0. To calculate the dot product, we only need to
check if the same key is in the other sparse vector.

- Complexity
  - Space: $O(n)$ to store the hash map(only the non zero elements) and $O(1)$
    the dot product calculation.
  - Time: $O(n)$ for calculating the dot product and the same for iterating over
    the given sparse vector on construction.
