class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = -pow(10,4) -1
        temp_res = 0
        for i in nums:
            temp_res += i
            if temp_res >= res:
                res = temp_res
            if temp_res < 0:
                temp_res = 0
        return res