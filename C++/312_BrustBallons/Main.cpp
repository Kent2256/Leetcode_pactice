You are given n balloons, indexed from 0 to n - 1. 
Each balloon is painted with a number on it represented by an array nums.
 You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:
1 3 1 5 8 1
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
            15          120        24       8
Example 2:

Input: nums = [1,5]
Output: 10
 
n!
Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<bool> cache(nums.size(),false);
        vector<priority_queue<int>> data(n);
        rec(nums,cache,data,0);
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int dp[301][301] = {};
        int naya[301] = {};
        int ti = 0;
        int n = nums.size();
        naya[ti++] = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) naya[ti++] = nums[i];
        }
        naya[ti++] = 1;

        for(int lim = 2; lim < ti; lim++) {
            for(int left = 0; left + lim < ti; left++) {
                int right = left + lim;
                for(int j = left + 1; j < right; j++) {
                    dp[left][right] = max(dp[left][right],
                    naya[left] * naya[j] * naya[right] + dp[left][j] + dp[j][right]);
                }
            }
        }

        // for(int i = 0; i < ti; i++) {
        //     for(int j = 0; j < ti; j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return dp[0][ti-1];
    }
};



