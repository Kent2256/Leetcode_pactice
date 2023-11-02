#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT32_MIN;
        for(int i =0; i< nums.size(); i ++){
            for(int k = nums.size()-1; k >=i;k--){
                int temp = 0;
                //cout << "left:" << i << "right:" << k<< endl;
                for(int l=i;l<=k; l++){
                    temp += nums[l];
                    //cout<< nums[l] << ",";
                }
                //cout << endl;
                res = max(temp,res);
            }
        }
        return res;
    }
    int maxSubArray(vector<int>& nums) {
        int res=INT32_MIN;
        int temp_res = 0;
        for (int num:nums){
            temp_res+= num;
            if(temp_res > res){
                res = temp_res;
            }
            if(temp_res < 0){
                temp_res = 0;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;
}