#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size() - 1;i++){
            if (nums[i] > 0) return result;
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                if((nums[l] + nums[r]) == -nums[i]){
                    if(i > 0 && nums[i] == nums[i-1]) break;
                    result.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }
                else if((nums[l] + nums[r]) > -nums[i]){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums ={-1,0,-1,1,2,-4};
    Solution sol;
    auto res = sol.threeSum(nums);
    for( auto vec1: res){
        cout << "{" ;
        for( auto num:vec1){
            cout << num << ",";
        }
        cout << "}" << endl;
    }
}