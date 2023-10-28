# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        left_list = []
        right_list = []
        n = len(nums)
        mid = n/2-1 if n%2 == 0 else (n/2)
        left_list = nums[:mid]
        right_list = nums[mid+1:]
        head = TreeNode() 
        head.val = nums[mid]
        if left_list:
            head.left = self.sortedArrayToBST(left_list)
        if right_list:
            head.right = self.sortedArrayToBST(right_list)
        return head
        