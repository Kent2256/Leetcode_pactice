#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for( int i = 0; i < nums.size(); i++){
            int remain = target - nums[i];
            if(map.find(remain) != map.end()){
                return {map[remain],i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 19;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    if (result.empty()){
        cout << "No result" << endl;
    }else{
        cout << result[0]  << " " << result[1] << endl;
        cout << nums[result[0]] << " " << nums[result[1]] << endl;
    }
    return 0;
};