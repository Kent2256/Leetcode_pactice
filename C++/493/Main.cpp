Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        unordered_map<int,int> map;
        int result=0;
        for(int num:nums){
            long long temp = num;
            temp*=2;
            for( auto it:map){
                if(it.first > temp){
                    result+=it.second;
                }
            }
            map[num]++;
        }
        return result;
    }
};

class Solution {
public:
    
    // Merge function to merge two sorted halves of the array
    void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp; // Temporary vector to store the merged result
        int left = low;   // Pointer for the left subarray
        int right = mid + 1; // Pointer for the right subarray

        // Compare elements from both subarrays and merge them into temp
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy remaining elements from the left subarray, if any
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from the right subarray, if any
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy the merged result back to the original array nums
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // Merge Sort function to sort and count reverse pairs
    int mergeSort(vector<int> &nums, int low, int high){
        int count = 0; // Counter for reverse pairs

        // Base case: if the subarray has one or zero elements, return 0
        if (low >= high) return count;

        int mid = low + (high - low) / 2; // Calculate the midpoint

        // Recursively sort and count reverse pairs in left and right subarrays
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);

        // Count reverse pairs between the left and right subarrays
        count += countPairs(nums, low, mid, high);

        // Merge the sorted subarrays
        merge(nums, low, mid, high);

        return count; // Return the total count of reverse pairs
    }

    // Function to count reverse pairs between two halves
    int countPairs(vector<int> &nums, int low, int mid, int high){
        int right = mid + 1; // Pointer for the right subarray
        int count = 0;       // Counter for reverse pairs

        // Iterate through the left subarray
        for (int i = low; i <= mid; i++) {
            // Find the rightmost element in the right subarray
            // that is greater than twice the value of the current element
            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            // Count the number of elements in the right subarray
            // that are less than or equal to half the value of the current element
            count += (right - (mid + 1));
        }
        return count; // Return the count of reverse pairs
    }

    // Main function to find and count reverse pairs in the array
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1); // Call mergeSort with the entire array
    }
};

