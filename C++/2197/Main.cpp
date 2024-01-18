You are given an array of integers nums. Perform the following steps:

Find any two adjacent numbers in nums that are non-coprime.
If no such numbers are found, stop the process.
Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
Repeat this process as long as you keep finding two adjacent non-coprime numbers.
Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in 
any arbitrary order will lead to the same result.

The test cases are generated such that the values in the final array are less than or equal to 108.

Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.

 

Example 1:

Input: nums = [6,4,3,2,7,6,2]
Output: [12,7,6]
Explanation: 
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
Example 2:

Input: nums = [2,2,1,1,3,3,3]
Output: [2,1,1,3]
Explanation: 
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
- (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [2,1,1,3].
Note that there are other ways to obtain the same resultant array.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
The test cases are generated such that the values in the final array are less than or equal to 108.


class Solution {
public:
    void LCM(int& num1, const int& num2, const int& gcd){
        num1 = num1/gcd*num2;
    }
    // int GCD(const int& num1, const int& num2){
    //     int min_val = min(num1,num2);
    //     if(num1%min_val==0 && num2%min_val==0) return min_val;
    //     min_val/=2;
    //     for(;min_val >1;min_val--){
    //         if(num1%min_val == 0 && num2%min_val==0)return min_val;
    //     }
    //     return 1;
    // }
    long long int GCD(long long int a, long long int b) {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1){
                res.push_back(1);
                continue;
            }
            else{
                int gcd=GCD(res.back(),nums[i]);
                if(gcd==1){
                    res.push_back(nums[i]);
                    continue;
                }
                else{
                    LCM(res.back(),nums[i],gcd);
                    while(res.size()>=2){
                        gcd = GCD(res.back(),res[res.size()-2]);
                        if(gcd!=1){
                            int temp=res.back();
                            res.pop_back();
                            LCM(res.back(),temp,gcd);
                        }
                        else break;
                    }
                }
            }
        }
        return res;    
    }
};