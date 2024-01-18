Given an integer array nums, return true if 
there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.


Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> result;
        result.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            auto it = lower_bound(result.begin(),result.end(),nums[i]);
            if(it==result.end()){
                result.push_back(nums[i]);
                if(result.size()==3)return true;
            }
            else *it = nums[i];
        }
        return false;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int left = INT_MAX;
       int right = INT_MAX;

       for (int num : nums) {
            if (num <= left) {
                left = num;
            } else if (num <= right) {
                right = num;
            } else {
                return true;
            }
        }
        return false;
    }
};