from typing import List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
    #     max_val = 1
    #     for num in nums:
    #         if num == 0:
    #             continue
    #         else:
    #             max_val *= num
    #     print(max_val)
    #     if 0 in nums:
    #         if nums.count(0) > 1:
    #             return [0 for _ in range(len(nums))]
    #         else:
    #             return [max_val if nums[i] == 0 else 0 for i in range(len(nums))]
    #     result = []
    #     for i in range(len(nums)):
    #         result.append(max_val // nums[i])
    #     return result
        left,right=1,1
        res=[]
        res2=[1] * len(nums)
        for n in nums:
            res.append(left)
            left*=n
        print(res)
        for i in range(len(nums)-1,-1,-1):
            res[i]*=right
            res2[i] = right
            right*=nums[i]
        print(res2)
        return res
if __name__ == '__main__':
    sol = Solution()
    nums = [1,2,3,4]
    print(sol.productExceptSelf(nums))
    nums = [-1,1,0,3,4]
    print(sol.productExceptSelf(nums))
    nums = [-1,1,0,0,3,4]
    print(sol.productExceptSelf(nums))
