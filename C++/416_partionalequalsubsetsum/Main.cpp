Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements
in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
acculate = 0

int sum = std::accumulate(myVector.begin(), myVector.end(), 0);

class Solution {
public:
    bool subset(vector<vector<int>>& dp,vector<int>& nums, int sum, int index){
        if(sum == 0) return true;
        if(sum < 0 || index >= nums.size()) return false;
        if(dp[index][target] != -1)
            return dp[index][target];
        dp[index][target] = (subset(dp,nums,sum,index + 1) || subset(dp,nums,sum-nums[index],index + 1));
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1) return false;
        sum = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return subset( dp,nums, sum ,0);
    }
};

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