class Solution:
    def _f(self, root, targetSum, path_sum):
        if not root:
            return False
        path_sum += root.val
        if path_sum == targetSum and not (root.left or root.right):
            return True
        if not root.left and not root.right:
            return False
        if self._f(root.left, targetSum, path_sum):
            return True
        if self._f(root.right, targetSum, path_sum):
            return True
        path_sum -= root.val
        return False

    def hasPathSum(self, root, targetSum):
        return self._f(root, targetSum, 0)
