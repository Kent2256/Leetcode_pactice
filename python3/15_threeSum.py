
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            if nums[i] > 0:
                return result
            l = i + 1
            r = len(nums) - 1
            val = -nums[i]
            while l < r:
                complient = nums[l] + nums[r]
                if complient == val:
                    result.append([nums[i],nums[l],nums[r]])
                    while l < r and nums[l] + nums[r] == val:
                        l += 1
                elif complient > val:
                    r -= 1
                else:
                    l += 1
        return result
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Sort the list first
        nums = sorted(nums)
        output = []
        
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
                
            if nums[i] > 0:
                continue
            val = -nums[i]
            start = i + 1
            end = len(nums) - 1
            while start < end:
                complement = nums[start] + nums[end]
                if complement == val:
                    output.append([-val, nums[start], nums[end]])
                    while start < end and nums[start] + nums[end] == complement:
                        start += 1
                elif complement < val:
                    start += 1
                else:
                    end -= 1
                    
        return output
if __name__ == '__main__':
    nums = [0,0,0,0]
    print(Solution().threeSum(nums))