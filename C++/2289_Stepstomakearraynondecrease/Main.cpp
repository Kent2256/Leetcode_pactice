You are given a 0-indexed integer array nums. In one step, remove all 
elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

Return the number of steps performed until nums becomes a non-decreasing array.

 

Example 1:

Input: nums = [5,3,4,4,7,3,6,11,8,5,11]
Output: 3
Explanation: The following are the steps performed:
- Step 1: [5,3,4,4,7,3,6,11,8,5,11] becomes [5,4,4,7,6,11,11]
- Step 2: [5,4,4,7,6,11,11] becomes [5,4,7,11,11]
- Step 3: [5,4,7,11,11] becomes [5,7,11,11]
[5,7,11,11] is a non-decreasing array. Therefore, we return 3.
Example 2:

Input: nums = [4,5,7,7,13]
Output: 0
Explanation : nums is already a non-decreasing array. Therefore, we return 0.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109


class Solution {
public:
    vector<int> step(vector<int>& nums){
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i] >= nums[i-1])res.push_back(nums[i]);
        }
        return res;
    }
    int totalSteps(vector<int>& nums) {
        vector<int> temp;
        int step=0;
        while(true){
            temp = step(nums);
            if(temp.size()==nums.size())break;
            else nums=temp;
            step++;
        }
        return step;
    }
};

int totalSteps(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> stack, dp(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && A[i] > A[stack.back()]) {
                dp[i] = max(++dp[i], dp[stack.back()]);
                stack.pop_back();
                res = max(res, dp[i]);
            }
            stack.push_back(i);
        }
        return res;
    }