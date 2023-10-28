from typing import List
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(nums)):
            new_res = []
            if not res:
                res.append([nums[i]])
                continue
            for k in range(i + 1):
                for j in range(len(res)):
                    temp = res[j].copy()
                    temp.insert(k, nums[i])
                    new_res.append(temp)
            res = new_res
        return res
    '''
        res = []
        if len(nums) == 1:
            return [nums[:]]

        for _ in range(len(nums)):
            # [1,2,3] -> [2,3]
            item = nums.pop(0)
            perms = self.permute(nums)
            for perm in perms: # [2, 3], [3, 2]
                perm.append(item) # [2, 3, 1], [3, 2, 1]

            res.extend(perms[:])
            nums.append(item) # -> [2, 3, 1] in the root

        return res
    '''
    '''
        results = []
        def recurse(nums, perm):
            if not nums:
                results.append(perm[:])
            for i in range(len(nums)):
                num = nums[i]
                perm.append(num)
                recurse(nums[:i] + nums[i+1:], perm)
                perm.pop()
        
        recurse(nums, [])
        return results
    '''

if __name__ == "__main__":
    nums = [1,2,3]
    print(Solution().permute(nums))
    # nums = [0]
    # print(Solution().permute(nums))