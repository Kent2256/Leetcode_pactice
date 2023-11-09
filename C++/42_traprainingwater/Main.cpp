#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //total water is trapped into the bars
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
        while(l<r){
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);
            ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
        }
        return ans;
    }
};

int main(){
    vector<int> height = {9,6,8,8,5,6,3};
    Solution sol;
    vector<int> height2 = {1,6,1,6,1,3,8,8,3,4,9,6,3,2,8,5,7};
    cout << sol.trap(height) << endl;
    cout << sol.trap(height2) << endl;
}