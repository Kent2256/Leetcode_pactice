#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target)return mid;
            //left side
            if(nums[mid] >= nums[0]){
                if(nums[0] <= target && target < nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid +1;
                }
            }
            // right side
            else{
                if(nums[mid] < target && target <= nums[nums.size()-1]){
                    l = mid + 1;
                }
                else{
                    r = mid -1;
                }
            }
        }
        return -1;
    }
};
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution sol;
    cout << sol.search(nums,target);
}