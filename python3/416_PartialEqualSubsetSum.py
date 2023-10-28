from typing import List
class Solution:
    '''
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)
        if total_sum%2: 
            return False
        else:
            cache = [False] * (total_sum//2 + 1)
            def dfs(i,nums, total, cache):
                for k in range(len(nums)):
                    if nums[k] + i <= total:
                        cache[nums[k]+i] = True
                        if nums[k] + i == total:
                            break
                        else:
                            dfs( nums[k]+i ,nums[k+1:], total, cache)
                return cache[total]
            return dfs(0,nums,total_sum//2,cache)
    '''
    def canPartition(self, nums: List[int]) -> bool:
        def rec(i,rsum):
            if(rsum==0): return True
            if(i==len(nums) or rsum < 0): return False 
            elif(self.dp[i][rsum] != -1 ):#visited
                return self.dp[i][rsum]
            self.dp[i][rsum]= rec(i+1,rsum-nums[i]) or rec(i+1,rsum)
            return self.dp[i][rsum]
        
        
        totalsum = sum(nums)
        if(totalsum%2): return False 
        else: 
            self.dp = [ [-1]*((totalsum//2)+1) for _ in range(len(nums))]
            return rec(0,totalsum//2)
    '''
    class Solution {
public:
    // 1. Using Recursion
    // TC - O(Exponential)
    bool canPartitionRec(int index, vector<int>& nums, int target)
    {
        // Base Case
        if(index >= nums.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        int include = canPartitionRec(index + 1, nums, target - nums[index]);
        int exclude = canPartitionRec(index + 1, nums, target);

        return (include or exclude);
    }

    // 2. Top Down Approach
    // TC and SC -- O(N * M)
    bool canPartitionMemo(int index, vector<int>& nums, int target, vector<vector<int>>& dp)
    {
        // Base Case
        if(index >= nums.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        if(dp[index][target] != -1)
            return dp[index][target];
        
        int include = canPartitionMemo(index + 1, nums, target - nums[index], dp);
        int exclude = canPartitionMemo(index + 1, nums, target, dp);

        dp[index][target] =  (include or exclude);
        return dp[index][target];
    }

    // 3. Bottom Up Approach
    // TC and SC -- O(N * M)
    bool canPartitionTab(vector<int> nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));

        for(int i = 0; i < n; i++)
            dp[i][0] = 1;
        
        for(int index = n - 1; index >= 0; index--)
        {
            for(int t = 1; t <= target; t++)
            {
                int include = 0;
                if(t - nums[index] >= 0)
                    include = dp[index + 1][t - nums[index]];
                int exclude = dp[index + 1][t];

                dp[index][t] =  (include or exclude);
            }
        }
        return dp[0][target];
    }

    // 4. Space Optimization
    // TC -- O(N * M) and SC -- O(N)
    bool canPartitionSO(vector<int> nums, int target)
    {
        int n = nums.size();
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);

        for(int i = 0; i < n; i++)
            curr[0] = 1;
        
        for(int index = n - 1; index >= 0; index--)
        {
            for(int t = 1; t <= target; t++)
            {
                int include = 0;
                if(t - nums[index] >= 0)
                    include = next[t - nums[index]];
                int exclude = next[t];

                curr[t] =  (include or exclude);
            }
            // Shift
            next = curr;
        }
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        cout << sum << endl;

        // We cannot divide odd number into two equal halves
        if(sum & 1) return false;

        int target = sum / 2;

        // return canPartitionRec(0,nums,target);

        // 2. Top Down
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // return canPartitionMemo(0,nums,target,dp);

        // 3. Bottom Up
        // return canPartitionTab(nums,target);

        // 4. Space Optimization
        return canPartitionSO(nums,target);
    }
    };
    '''

if __name__ == '__main__':
    nums = [1,2,5]
    s = Solution()
    print(nums)
    print(s.canPartition(nums))

    nums = [1,1,2,2]
    print(nums)
    print(s.canPartition(nums))

    # nums = [100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97]
    # print(s.canPartition(nums))