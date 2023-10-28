# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        BST_value_list = []
        def value_BST(root):
            if root is None:
                return None
            if root.left:
                value_BST(root.left)

            BST_value_list.append(root.val)
            
            if root.right:
                value_BST(root.right)
            return None
        value_BST(root)    
        return BST_value_list == sorted(set(BST_value_list))
    '''
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.prev = -math.inf

        def inOrder(node):
            # process left, root, then right
            if not node:
                return True

            if not inOrder(node.left):
                return False

            # inorder traversal: must be strictly increasing for BST
            if node.val <= self.prev:
                return False
            self.prev = node.val
            return inOrder(node.right)

        return inOrder(root)
    '''