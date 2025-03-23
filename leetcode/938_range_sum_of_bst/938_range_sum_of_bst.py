# https://leetcode.com/problems/range-sum-of-bst
from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0

    def search_in_range(self, root: Optional[TreeNode], low: int, high: int):
        if root is None:
            return
        if low <= root.val and root.val <= high:
            self.sum += root.val
        if low <= root.val:
            self.search_in_range(root.left, low, high)
        if root.val <= high:
            self.search_in_range(root.right, low, high)

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.search_in_range(root, low, high)
        return self.sum
