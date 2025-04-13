# https://leetcode.com/problems/binary-tree-level-order-traversal
from collections import deque
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        lvls = []
        if root:
            q.append(root)
        while len(q):
            lvl = []
            for i in range(len(q)):
                curr = q.popleft()
                lvl.append(curr.val)
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            lvls.append(lvl)
        return lvls
