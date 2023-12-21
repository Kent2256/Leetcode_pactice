You are given a 0-indexed array of integers nums of length n. 
You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:     0 1
               1 2         size = 5
Input: nums = [2,3,1,1,4]
Output: 2      2 4
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
               0 1 2 2 2
Input: nums = [2,3,0,1,4]
Output: 2
     0 1 2 3 4
    [1,2,1,1,1]
n    0
cou  0
pq   1
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1 )return 0;
        int n=0,count=0;
        priority_queue<int> pq;
        for(int i=0; i <nums.size();i++){
            if(i>n){
                count++; 
                n=pq.top();
            }
            if((i+nums[i]) > n){
                pq.push(i+nums[i]);
            }
            if((i+nums[i])  >= nums.size()-1){
                count++;
                break;
            }
        }
        return count;
    }
};
 