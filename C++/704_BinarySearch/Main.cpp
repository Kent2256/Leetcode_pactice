#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1, mid;
        while(l <= r){
            mid = (l+r)/2;
            if (nums[mid] == target)return mid;
            else if(nums[mid] > target)r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums={-1,0,3,5,9,12};
    int target = 9;
    Solution sol;
    cout << sol.search(nums, target) << endl;

    vector<int> nums2={-1,0,3};
    int target2 = 3;
    cout << sol.search(nums2, target2) << endl;
};