from typing import List
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l,r = 0, len(nums)-1
        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid
            #left sorted
            if nums[0] <= nums[mid]:
                if nums[0] <= target < nums[mid]:
                    r = mid-1
                else:
                    l = mid+1
            # right sorted
            if nums[0] > nums[mid]:
                if nums[mid] < target <= nums[-1]:
                    l = mid+1
                else:
                    r = mid-1
        return -1
    
if __name__ == "__main__":
    nums = [4,5,6,7,0,1,2]
    target = 0
    print(Solution().search(nums, target))
    nums = [0,1,2,4,5,6,7]
    target = 0
    print(Solution().search(nums, target))