Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 positive 0 negative
 _>
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

  [2,3,-2,4,6-1]
 1 2 6 1 4 6 falg-1*flag*i-1*i
      flag    72
    [2,3,-2,4,0,-1]
    1,2,6 1 4 1 1
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
[2,-5,-2,-4,3]
 2 -10 20 -80 -240
 -240   -120   24   -12  3

class Solution {
public:
    int getmax(vector<int>& nums) {
        int dp[nums.size()+1];
        int val=nums[0];
        dp[0]= 1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                dp[i+1] = dp[i]*nums[i];
                val = max(dp[i+1],val);
            }
            else{
                dp[i+1] = 1;
                val = max(nums[i],val);
            }
        }
        return val;
    }
    int maxProduct(vector<int>& nums){
        int res = getmax(nums);
        reverse(nums.begin(),nums.end());
        int res2 = getmax(nums);
        return max(res,res2);
    }
};