// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int>& nums, int index,vector<int> subset){
        if(index == nums.size()){
            res.push_back(subset);
            return;
        }
        if(subset.empty() || subset.back() != nums[index]){
            backtrack(res,nums,index+1,subset);
        }
        subset.push_back(nums[index]);
        backtrack(res,nums,index+1,subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        backtrack(res,nums,0,{});
        return res;
    }
};

int main(){
    vector<int> nums= {1,2,2};
    Solution sol;
    vector<vector<int>> res = sol.subsetsWithDup(nums);
    for(vector<int> sub_res:res){
        cout << "{";
        for(int i:sub_res){
            cout << i << ",";
        }
        cout << "}" << endl;
    }
}