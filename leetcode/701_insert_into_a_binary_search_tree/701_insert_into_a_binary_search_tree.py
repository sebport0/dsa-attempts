# https://leetcode.com/problems/insert-into-a-binary-search-tree
import pytest
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.right = right
        self.left = left


class Solution:
    def insertIntoBSTRecursive(
        self, root: Optional[TreeNode], val: int
    ) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        if val > root.val:
            root.right = self.insertIntoBSTRecursive(root.right, val)
        elif val < root.val:
            root.left = self.insertIntoBSTRecursive(root.left, val)
        return root

    def insertIntoBSTIterative(
        self, root: Optional[TreeNode], val: int
    ) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        pointer = root
        while True:
            if val > pointer.val:
                if not pointer.right:
                    pointer.right = TreeNode(val)
                    return root
                pointer = pointer.right
            elif val < pointer.val:
                if not pointer.left:
                    pointer.left = TreeNode(val)
                    return root
                pointer = pointer.left
