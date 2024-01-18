// You are given an array of integers nums, there is a sliding window of size k which is moving from the very 
//left of the array to the very right. You can only see the k numbers in the window. 
//Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// 1 
// 1
// 1 3
// 3
// 1 3 -1 -2 2
// 3  
// 2 1 @-1 2 1 {} empty max2
// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <deque>
using namespace std;
class maxqueue{
    queue<int> q1;
    deque<int> qmax;
public:    
    maxqueue(){
    }
    
    void push(int k){
        q1.push(k);
        while(!qmax.empty() && k > qmax.back()){
            qmax.pop_back();
        }
        qmax.push_back(k);
    }
    void pop(){
        int val = q1.front();
        q1.pop();
        if(val == qmax.front())qmax.pop_front();
    }

    int getMax(){
        return qmax.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i] > q.top())q.pop();
            q.push(nums[i]);
        }
        res.push_back(q.top());
        for(int i=k;i < nums.size();i++){
            if(nums[i-k] == q.top())q.pop();
            while(!q.empty() && nums[i] > q.top())q.pop();
            q.push(nums[i]);
            res.push_back(q.top());
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<int> res = sol.maxSlidingWindow(nums,k);
    for( auto i: res) cout << i << ",";
    cout << endl;
}


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        int i=0,j=0;
        vector<int>sol;
        while(j < nums.size()) {
            while(!q.empty() && q.back()<nums[j]) {
                q.pop_back();
            }
            q.push_back(nums[j]);
            if(j-i+1==k) {
                sol.push_back(q.front());
                if(nums[i]==q.front()) {
                    q.pop_front();
                }
                i++;
            }
            j++;
        }
        return sol;
    }
};