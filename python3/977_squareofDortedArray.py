class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def square(num):
            return num * num
        res = list(map(square,nums))
        #list sor faster than sorted()list
        res.sort()
        return res
        