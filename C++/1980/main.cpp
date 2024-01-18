Given an array of strings nums containing n unique binary strings each of length n, 
return a binary string of length n that does not appear in nums. 
If there are multiple answers, you may return any of them.

 

Example 1:
01 10 11
1^0^0=1
1^1^0=0
1^1^1=1
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 
111
011
001
110
Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique. 

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<int> res_int(n,1);
        int index=0;
        for(string num:nums){
            res_int[index] ^= (num[index]-'0');
            index++;
        }
        string result;
        for(int i:res_int){
            if(i)result+="1";
            else result+="0";
        }
        return result;
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int m=nums.size();int n=nums[0].size();
        string s;int i=0;
        for(int k=0;k<min(n,m);k++)
        {
            if(nums[i][i]=='0')s+="1";
            else s+="0";
            i++;
        }
        for(int k=i;k<n;k++)s+="1";
        return s;
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;

        int index = 0;
        for(auto binary : nums)
        {
            ans = ans + to_string('1' - binary[index]);
            index+=1;
        }
        return ans;
    }
};