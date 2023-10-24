class Solution(object):
    def twoSum(self, nums, target):
        dict_temp = {}
        for i, num in enumerate(nums):
            if num in dict_temp:
                return [dict_temp[num], i]
            else:
                dict_temp[target - num] = i
        return []
    
if __name__ == '__main__':
    soultion = Solution()
    nums = [2,4,5,6,3]
    target = 11
    print(soultion.twoSum(nums,target))