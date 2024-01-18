Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1 
Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0; int sum=0;
        unordered_map<int,int> map;
        map[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i] ? 1:-1;
            if(map.find(sum)!=map.end()) res = max(res, i-map[sum]);
            else map[sum] = i;
        }
        return res;
    }
};