"""
https://leetcode.com/problems/guess-number-higher-or-lower

Time: O(logn), range is halved on every iteration.
Memory: O(1), no extra space is allocated.

Solved with binary search, this time the target is unknown,
instead a rule is given.
"""

import pytest


def guess(num: int, pick: int = 6) -> int:
    if num < pick:
        return 1
    elif num > pick:
        return -1
    return 0


class Solution:
    def guessNumber(self, n: int, pick: int) -> int | None:
        left = 1
        right = n
        while True:
            attempt = (left + right) // 2
            result = guess(attempt, pick)
            if result == 0:
                return attempt
            elif result == -1:
                right = attempt - 1
            else:
                left = attempt + 1


@pytest.mark.parametrize("n,pick", [(10, 6), (1, 1), (2, 1), (5, 3), (3, 3)])
def test_solution(n, pick):
    s = Solution()
    out = s.guessNumber(n, pick)
    assert out == pick
