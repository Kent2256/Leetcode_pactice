from typing import List
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        result = []
        m = len(nums)
        def rec(i, cur):
            if i == m:
                result.append(cur)
                return
            if i > m:
                return
            rec(i+1, cur + [nums[i]])
            rec(i+1, cur)
        rec(0,[])
        return result
        
        

if __name__ == "__main__":
    nums = [1,2,3]
    s = Solution()
    print(s.subsets(nums))
 