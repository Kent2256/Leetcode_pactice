# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        return self.rootpath(root,1) != -1

    def rootpath(self, root, depth):
        if not root:
            return 0
        l = self.rootpath(root.left, depth)
        r = self.rootpath(root.right, depth)
        if abs(l-r) > 1 or l == -1 or r == -1:
            return -1
        return 1 + max(l,r)
