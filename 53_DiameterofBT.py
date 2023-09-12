# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    res = 0
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root):
            if not root:
                return 0
            res_left = dfs(root.left)
            res_right = dfs(root.right)
            self.res = max(self.res, res_left + res_right) # Sum the height of left tree and right tree
            return max(res_left, res_right) + 1
        dfs(root)
        return self.res
        
        