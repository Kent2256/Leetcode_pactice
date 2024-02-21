Given an array of integers arr, find the sum of min(b), 
where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.


Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 3 1 2 4
 1 1 2
 1 1
 1
Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        arr.push_back(INT_MAX);
        int sum=0;
        for(int k=n;k>0;k--){
            for(int i=0;i<k;k++){
                sum+=arr[i];
                arr[i] = min(arr[i],arr[i+1]);
            }
        }
        return sum;
    }
};
