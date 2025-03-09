# https://leetcode.com/problems/binary-search/
import pytest
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            middle = (left + right) // 2
            if target < nums[middle]:
                right = middle - 1
            elif target > nums[middle]:
                left = middle + 1
            else:
                return middle
        return -1


@pytest.mark.parametrize(
    "nums, target, expected",
    [
        ([1, 2, 3], 2, 1),
        ([-1, 0, 3, 5, 9, 12], 9, 4),
        ([-1, 0, 3, 5, 9, 12], 2, -1),
    ],
)
def test_search(nums, target, expected):
    s = Solution()
    out = s.search(nums, target)
    assert out == expected
