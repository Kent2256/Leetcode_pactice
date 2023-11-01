# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        cur = [0]
        def right_order(level,root: Optional[TreeNode]):
            if not root:
                return
            if level > cur[0]:
                result.append(root.val)
                cur[0] = level
            right_order(level+1, root.right)
            right_order(level+1, root.left)
        right_order(1,root)
        return result
    '''
            def dfs(root,h,ret) -> List[int]:
            if not root:
                return ret
            if h == len(ret):
                ret.append(root.val)
            h += 1
            ret = dfs(root.right,h,ret)
            return dfs(root.left,h,ret)
        return dfs(root,0,[])
    '''    