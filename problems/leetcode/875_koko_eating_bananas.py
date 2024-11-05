# https://leetcode.com/problems/koko-eating-bananas
import math
from typing import List
import pytest


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        result = right
        while left <= right:
            candidate = (left + right) // 2
            i = 0
            for pile in piles:
                i += math.ceil(float(pile) / candidate)
            if i <= h:
                result = candidate
                right = candidate - 1
            else:
                left = candidate + 1
        return result


@pytest.mark.parametrize(
    "piles, h, expected",
    [
        ([312884470], 312884469, 2),
        ([3, 6, 7, 11], 8, 4),
        ([30, 11, 23, 4, 20], 5, 30),
        ([30, 11, 23, 4, 20], 6, 23),
    ],
)
def test_solution(piles, h, expected):
    s = Solution()
    got = s.minEatingSpeed(piles, h)
    assert got == expected


"""
# Takeaways

  * len(piles) <= h is key. It confirms that the problem always has a solution,
    max(piles) being the worst case.
  * In my first attempt, I did piles[i] = max(0, piles[i] - candidate) which
    modifies the array in place, which is almost always a bad idea.
  * I should've started with a brute force solution. What led me to the binary
    search attempt was len(piles) <= h and realizing that the solution must
    be in {1, 2,...,max(piles)} which is an ordered set, which makes binary
    search very tempting.
  * As a general rule, If I'm making modifications in place and copies of a
    given data structure I should stop and simplify.
"""
