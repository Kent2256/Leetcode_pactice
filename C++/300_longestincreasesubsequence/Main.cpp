// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

// Example 1:
//                 8
// Input: nums = [10,9,3,5,2,7,101,18]
// Output: 4      8  7 6 6 5 5  5  4
               
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4      1 1 0 1 0 1
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1      1
 
//  [4,10,2,3,8,9]
  
// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         vector<int> arr;
         arr.push_back(nums[0]);
         for(int i=1; i<nums.size(); i++)
         {
             auto it=lower_bound(arr.begin(), arr.end(), nums[i]);
             if(it==arr.end())  arr.push_back(nums[i]);
             else   *it=nums[i];
         }
         for(int i:arr)cout << i <<",";
         return arr.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DP
        // dp[i]: current longest no.
        int results = 0;
        vector<int> dp(nums.size(), 1);
        // for dp[i]
        for (int i = 0; i < nums.size(); ++i) {
            // compare every nums[j] with nums[i]
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > results) results = dp[i];
        }
        return results;
    }
};
[10,9,3,5,2,7,101,18]
 1  1 1 2 1 3 4   4

 [4,10,2,3,8,9]