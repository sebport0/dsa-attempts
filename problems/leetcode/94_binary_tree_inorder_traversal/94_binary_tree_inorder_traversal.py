# https://leetcode.com/problems/binary-tree-inorder-traversal
import pytest
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.right = right
        self.left = left


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def traverse(root: Optional[TreeNode], out: List[int]) -> List[int]:
            if not root:
                return []
            traverse(root.left, out)
            out.append(root.val)
            traverse(root.right, out)
            return out

        return traverse(root, [])
