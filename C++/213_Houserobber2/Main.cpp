You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:      2,3
                3,2
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,1,3,2]  
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> no_1(nums.begin()+1,nums.end());
        vector<int> no_end(nums.begin(),nums.end()-1);
        int m = no_1.size();
        vector<int> res1(m,0),res2(m,0);
        res1[0] = no_1[0]; res1[1]=no_1[1];
        res2[0] = no_end[0]; res2[1]=no_end[1];
        for(int i=2; i < m; i++){
            res1[i] = max(res1[i-1], res1[i-2]+no_1[i]);
            res2[i] = max(res2[i-1], res2[i-2]+no_end[i]);
        }
        return max(res1.back(),res2.back());
    }
};
int rober2(vector<int> street){
    vector<int> no_1(street.begin()+1,street.end());
    vector<int> no_end(street.begin(),street.end()-1);
    int m = no_1.size()-1;
    vector<int> res1(m),res2(m);
    res1[0] = no_1[0]; res1[1]=max(no_1[0],no_1[1]));
    res2[0] = no_end[0]; res2[1]=max(no_end[0],no_end[1]);
    for(int i=2; i < m; i++){
        res1[i] = max(res1[i-1], res1[i-2]+no_1[i]);
        res2[i] = max(res2[i-1], res2[i-2]+no_end[i]);
    }
    return max(res1.back(),res2.back());
}

[1,3,1,3,100]
 