#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num:nums){
            map[num]++;
            if (map[num] > (nums.size()/2)){
                return num;
            }
        }
        return -1;
    }
    int majorityElement2(vector<int>& nums) {
        int count=0,majority = 0;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            if(count==0){
                count++;
                majority = nums[i];
            }
            else if (nums[i] == majority){
                count++;
            }
            else{
                count--;
            }
        }
        return majority;
    }
};

int main(){
    vector<int> nums = {2,2,2,1,1,1,1,1,2,2};
    Solution sol;
    cout << "Majority element is" << sol.majorityElement(nums) << endl;
}