from collections import Counter

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return
        if self.bft(root, p) and self.bft(root,q):
            if self.lowestCommonAncestor(root.left,p,q):
                root = self.lowestCommonAncestor(root.left,p,q) 
            if self.lowestCommonAncestor(root.right,p,q):
                root = self.lowestCommonAncestor(root.right,p,q) 
        else:
            return
        return root

    def bft(self, root, p):
        if not root:
            return False
        if root.val != p.val:
            return self.bft(root.left,p) or self.bft(root.right,p)
        else:
            return True
        
    def lowestCommonAncestor2(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while True:
            if root.val < min(p.val,q.val):
                root = root.right
            elif root.val > max(p.val,q.val):
                root = root.left
            else:
                return root