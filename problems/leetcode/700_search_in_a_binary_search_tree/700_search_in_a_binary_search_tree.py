# https://leetcode.com/problems/search-in-a-binary-search-tree/
from typing import Optional
import pytest


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self) -> str:
        return f"""{self.val}->left=[{self.left}], right=[{self.right}]"""

    def __eq__(self, obj) -> bool:
        if isinstance(self, obj.__class__):
            return (
                self.val == obj.val
                and self.left == obj.left
                and self.right == obj.right
            )
        return False


class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root or root.val == val:
            return root
        elif root.val > val:
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)

    def searchBSTIterative(
        self, root: Optional[TreeNode], val: int
    ) -> Optional[TreeNode]:
        while root:
            if root.val == val:
                return root
            if root.val > val:
                root = root.left
            else:
                root = root.right
        return None


def test_solution():
    t1 = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7))
    expected = TreeNode(2, TreeNode(1), TreeNode(3))
    s = Solution()
    print(s)
    got = s.searchBST(t1, 2)
    assert expected == got
    got = s.searchBST(t1, 5)
    expected = None
    assert expected == got


def test_iterative_solution():
    t1 = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7))
    expected = TreeNode(2, TreeNode(1), TreeNode(3))
    s = Solution()
    print(s)
    got = s.searchBSTIterative(t1, 2)
    assert expected == got
    got = s.searchBST(t1, 5)
    expected = None
    assert expected == got
