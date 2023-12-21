You are given an integer array nums. 
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:
               0 1 2 3 4
Input: nums = [2,3,1,1,4]
Output: true
            n  2 4 4 4
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2: 
Input: nums = [3,2,1,0,4]
Output: false    1 1 1
                   1 1
                     1 0
            [3,0,0,0]
               1 1 1
Explanation: You will always arrive at index 3 no matter what. 
Its maximum jump length is 0, which makes it impossible to reach the last index.
'
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = 0;
        for(int i =0; i<=n && i<nums.size() ;i++){
            n= max(nums[i]+i,n);
            if(n >= nums.size()-1) return true;
        }
        return false;
    }
};