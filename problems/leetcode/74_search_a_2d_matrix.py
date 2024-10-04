# https://leetcode.com/problems/search-a-2d-matrix
from typing import List
import pytest


# Run: O(mlogn), Mem: O(1)
class Solution:
    def _binary_search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1
        while left <= right:
            middle = (left + right) // 2
            if target < nums[middle]:
                right = middle - 1
            elif target > nums[middle]:
                left = middle + 1
            else:
                return True
        return False

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            target_in_row = self._binary_search(row, target)
            if target_in_row:
                return True
        return False


@pytest.mark.parametrize(
    "matrix, target, want",
    [
        ([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 3, True),
        ([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 13, False),
    ],
)
def test_search_matrix(matrix, target, want):
    s = Solution()
    got = s.searchMatrix(matrix, target)
    assert got == want
