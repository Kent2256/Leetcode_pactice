class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        zeros = nums.count(0)
        for i in range(zeros):
            nums.remove(0)
            nums.append(0)
        return nums
    
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = 0

        for i in range(0,len(nums)):
            if nums[i]!= 0:
                if i!=n:
                    nums[n], nums[i] = nums[i], 0
                n+=1
        return nums
    