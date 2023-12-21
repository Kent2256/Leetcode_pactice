// Given a collection of candidate numbers (candidates) and a target number (target), 
//find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, vector<int> subset, int index, int target){
        if(target == 0){
            res.push_back(subset);
            return;
        }
        if(index == candidates.size())return;
        while( index < candidates.size() && target - candidates[index] >= 0){
            subset.push_back(candidates[index]);
            backtrack(res,candidates,subset,index+1,target - candidates[index]);
            subset.pop_back();
            index++;
            while(index < candidates.size() && candidates[index-1] == candidates[index])index++;
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        backtrack(res,candidates,{},0,target);
        return res;
    }
};

int main(){
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum2(candidates,target);
    for(vector<int> sub_res:res){
        cout << "{";
        for(int i:sub_res){
            cout << i << ",";
        }
        cout << "}" << endl;
    }
}