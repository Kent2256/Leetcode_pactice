You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer 
in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
  1 1 1 1 1
0           
1
2
3           
Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000


class Solution {
public:
    void rec(vector<int>& nums, int target, int index, int & res){
        if(target==0 && index==nums.size()){
            res++;
            return;
        }
        if(index >= nums.size()) return;
        rec(nums,target+nums[index],index+1,res);
        rec(nums,target-nums[index],index+1,res);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        rec(nums,target,0,res);
        return res;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if( abs(target) > sum) return 0;
        if((sum + target)&1) return 0;
        int new_target = (target+sum)/2;
        vector<int> dp(new_target+1,0);
        dp[new_target] = 1;
        for(int num:nums){
            for(int i=0; i <=new_target-num;i++){
                dp[i] += dp[i+num];
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //
        int sum = 0;
        for (auto n: nums) sum += n;
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2) return 0;
        int size = (target + sum) / 2;

        vector<int> dp(size + 1, 0); // dp[i] => number of ways to get i
        dp[0] = 1;
        for (auto n: nums) {
            for (int i = size; i >= n; i --) {
                dp[i] += dp[i - n];
                //cout << i << " " << dp[i] << endl;
            }
        }
        return dp[size];
    }
};


