from typing import List
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #nums.sort()
        d = {0: 0, 1: 0, 2: 0}
        for n in nums:
            d[n] += 1

        for i in range(d[0]):
            nums[i] = 0
        for k in range(d[0], d[0] + d[1]):
            nums[k] = 1
        for j in range(d[0]+d[1], d[0] + d[1] + d[2]):
            nums[j] = 2
            
        