#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int caculate( vector<int>& heigh,int index1, int index2){
        return min(heigh[index1],heigh[index2]) * (index2-index1);
    }  
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int cur,res = 0;
        while (left < right){
            cur = caculate(height,left,right);
            res = max(cur,res);
            if (height[left] < height[right]){
                left ++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout << sol.maxArea(height) << endl;
}