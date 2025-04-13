# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        return f"({self.val}, {self.left.val}, {self.right.val})"


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not inorder or not preorder:
            return None
        root = TreeNode(val=preorder[0])
        middle = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:middle+1], inorder[:middle])
        root.right = self.buildTree(preorder[middle+1:], inorder[middle+1:])
        return root

    def inorder(self, root: Optional[TreeNode]):
        if not root:
            return
        self.inorder(root.left)
        print(root.val)
        self.inorder(root.right)

    def preorder(self, root: Optional[TreeNode]):
        if not root:
            return
        print(root.val)
        self.preorder(root.left)
        self.preorder(root.right)


if __name__ == "__main__":
    # tree = TreeNode(
    #     val=3, left=TreeNode(9), right=TreeNode(20, TreeNode(15), TreeNode(7))
    # )
    # tree = TreeNode(val=3, left=TreeNode(9), right=TreeNode(20))
    tree = TreeNode(
        val=3, left=TreeNode(9, TreeNode(1), TreeNode(2)), right=TreeNode(20)
    )
    s = Solution()
    print(">> inorder:")
    s.inorder(tree)
    print(">> preorder:")
    s.preorder(tree)
