You are given a 0-indexed array of n integers arr.

The interval between two elements in arr is defined as the absolute difference between their indices. 
More formally, the interval between arr[i] and arr[j] is |i - j|.

Return an array intervals of length n where intervals[i] is the 
sum of intervals between arr[i] and each element in arr with the same value as arr[i].

Note: |x| is the absolute value of x.

 

Example 1:

Input: arr = [2,1,3,1,2,3,3]
Output: [4,2,7,2,4,4,5]
Explanation:
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
Example 2:

Input: arr = [10,5,10,10]
Output: [5,0,3,4]
Explanation:
- Index 0: Two more 10s are found at indices 2 and 3. |0 - 2| + |0 - 3| = 5
- Index 1: There is only one 5 in the array, so its sum of intervals to identical elements is 0.
- Index 2: Two more 10s are found at indices 0 and 3. |2 - 0| + |2 - 3| = 3
- Index 3: Two more 10s are found at indices 0 and 2. |3 - 0| + |3 - 2| = 4
2 5 6
7 4 
7-3*(size-i-1) +3*(i-1)=4
4-1*(size-i-1) +1*(i-1)=5
Constraints:

n == arr.length
1 <= n <= 105
1 <= arr[i] <= 105

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n =arr.size();
        vector<long long> res(n,0);
        unordered_map<int,vector<int>> map;
        for(int i=0;i< n;i++){
            map[arr[i]].push_back(i);
        }
        for(auto it:map){
            auto indexes=it.second;
            int length = indexes.size()
            long long total=0;
            for(int i=0;i<length;i++)total += indexes[i] - indexes[0];
            res[indexes[0]] = total;
            for(int i=1;i<length;i++){
                total += (indexes[i] - indexes[i-1]) * (i-1);
                total -= (indexes[i] - indexes[i-1]) * (length-i-1);
                res[indexes[i]] = total;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> ans(n);
        unordered_map<int , vector<int>> mp;
        
        // Store all the indices fop every unique numbers that exist.
        for(int i = 0 ; i < nums.size() ; i++) {
            mp[nums[i]].push_back(i);
        } 
        
        /*
          Access the vector for every unique number and for every index position 
          in the vector , find out the sum of absolute diff (considering the left side + right side).
          
          The concept of how we are finding out the absolute diff from both side
          for the curr index is shown in the pictures.
        */
        for(auto it : mp) {
           auto indexes = it.second;
           
           long long totalSum = 0;
           for(auto index : indexes) {
               totalSum += index;
           }
            
           long long preSum = 0;
           for(int i = 0 ; i < indexes.size() ; i++) {
               int index = indexes[i];
               long long postSum = totalSum - preSum - index;
               
               // Taking the left side for the curr index --> (i * count) - preSum;
               ans[index] += (index * (long long)i);
               ans[index] -= preSum;
               
               // Taking the right side for the curr index --> postSum - (i * count);
               ans[index] -= (index * (long long)(indexes.size() - i - 1));
               ans[index] += postSum;
               
               preSum += index;
           }
        }
        return ans;
    }
};

class Solution 
{
public:
    vector<long long> getDistances(vector<int>& arr) 
    {
        std::unordered_map<int, std::vector<int>> map;
        int n = arr.size();

        for (int i = 0; i < n; ++i)
            map[arr[i]].push_back(i);

        std::vector<long long> answer(n, 0);
        for (const auto& element : map)
        {
            const std::vector<int>& indexList = element.second;
            int length = indexList.size();
            
            long long result = 0;
            for (int i = 0; i < length; ++i)
                result += (indexList[i] - indexList[0]);
            answer[indexList[0]] = result;

            for (int i = 1; i < length; ++i)
            {
                int index = indexList[i];

                result += (indexList[i] - indexList[i - 1]) * i;
                result -= (indexList[i] - indexList[i - 1]) * (length - i);
                
                answer[index] = result;
            }
        }

        return answer;
    }
};