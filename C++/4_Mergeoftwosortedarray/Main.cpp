Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n=nums2.size();
        double result;
        if(m == 0){
            if(n&1)return nums2[n/2+1];
            result = (nums2[n/2] + nums2[n/2+1])/2;
            return result;
        }
        else if (n == 0){
            if(m&1)return nums1[m/2+1];
            result = (nums1[m/2] + nums1[m/2+1])/2;
            return result;
        }
        int l1=m/2, l2 =n/2;
        while(l1 >= 0 )
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged{};
        int j = 0;
        int l1 = nums1.size();
        int l2 = nums2.size();
        while(j < l2  && 0 < l1  && nums2[j] < nums1[0]){
            merged.push_back(nums2[j]);
            j++;
        }
        int i = 0;
        for(int n1 : nums1){
            merged.push_back(n1);
            while(j < l2  && i+1 < l1  && nums2[j] <= nums1[i+1]){
                merged.push_back(nums2[j]);
                j++;
            }
            i++;
        }
        while(j < l2){
            merged.push_back(nums2[j]);
            j++;
        }
        if(merged.size() > 1 && merged.size()%2 == 0){
            return (merged[merged.size()/2-1] + merged[merged.size()/2])/2.0;
        }else{
            return merged[merged.size()/2];
        }
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Ensure nums1 is smaller than nums2
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int n1 = nums1.size(), n2 = nums2.size();
    int begin = 0, end = n1;

    while (begin <= end) {
        int i1 = (begin + end) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int min1 = (i1 == n1) ? INT_MAX : nums1[i1];
        int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
        int min2 = (i2 == n2) ? INT_MAX : nums2[i2];
        int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];

        if (max1 <= min2 && max2 <= min1) {
            if ((n1 + n2) % 2 == 0) {
                return (double)(max(max1, max2) + min(min1, min2)) / 2;
            } else {
                return (double)max(max1, max2);
            }
        } else if (max1 > min2) {
            end = i1 - 1;
        } else {
            begin = i1 + 1;
        }
    }

    return 0.0;
}

};