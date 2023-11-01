class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isSameTree(p, q):
            if not p and not q:
                return True
            elif not p or not q:
                return False
            elif p.val != q.val:
                return False
            return isSameTree(p.right,q.left) and isSameTree(p.left,q.right)
        
        return isSameTree(root.right, root.left)