Given a sorted integer array arr, two integers k and x, 
return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = find(arr.begin(),arr.end(),x);
        if(it == arr.end()){
            if(x < arr[0]) return {arr.begin(),arr.begin()+k};
            else if (x > arr.back()) return {arr.end()-k,arr.end()};
            else{
                it = lower_bound(arr.begin(),arr.end(),x);
            }
        }
        deque<int> q;
        auto left = it-1, right=it;
        while(q.size()!=k){
                if( left < arr.begin() || abs(*left-x) > abs(*right-x)){
                    q.push_back(*right);
                    right++;
                }
                else if (right >= arr.end() || abs(*left-x) <= abs(*right-x)){
                    q.push_front(*left);
                    left--;
                }
        }
        return {q.begin(),q.end()};
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>&a,int k,int x){
        int l=0,h= a.size()-k-1;
        while(l<=h){
            int m=(l+h)/2;
            if(x-a[m]>a[m+k]-x)l=m+1;
            else h=m-1;
        }return vector<int>(a.begin()+l,a.begin()+l+k);
    }
};