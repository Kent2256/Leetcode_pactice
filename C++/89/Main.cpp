An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

 

Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]
 

Constraints:

1 <= n <= 16

class Solution {
public:
    bool isGood(int a, int b){
        int bits = a^b;
        return bits && !(bits & (bits-1));
    }
    bool add_value(vector<int>& result,queue<int>& q){
            if(q.empty())return true;
            for(int i=0;i<q.size();i++){
                int index = q.front();
                q.pop();
                if(isGood(index,result.back())){
                    result.push_back(index);
                    if(add_value(result,q)) return true;
                    else {
                        result.pop_back();
                        q.push(index);
                        }
                    }
                else q.push(index);
            }
            return false;
    }
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = pow(2,n);
        result.push_back(0);
        queue<int> q;
        for(int i=1;i<size;i++)q.push(i);
        add_value(result,q);
        return result;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) return {0,1};
        vector<vector<int>> result(n,vector<int>(pow(2,n),0));
        result[0][0]=0;result[0][1]=1;
        int stand=2;
        for(int i=1;i<n;i++){
            for(int k=0;k<stand;k++){
                result[i][k+1]=result[i-1][k]+stand;
            }
            for(int k=stand-1;k>0;k--){
                result[i][2*stand - k] = result[i-1][k];
            }
            stand*=2;
        }
        return result[n-1];
    }
};
[0,1]
 0 1
[0,2,3,1] 111
 00 10 11 01
[0,1,3,2,6,7,5,4]
000 100 110 111 101 001 011 010
0   4   6   7   5   1   3   2

00
01
10
11

class Solution {
public:
    vector<int> grayCode(int n) {
        int s = 1 << n;
        vector<int> ans(s);
        for(int i=0;i<(s);i++){
           ans[i] = i^(i>>1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        // 1<<n gives us left shift of 1 by n, which is basically 2 to the power n
        vector<int> ans(1<<n);

        for (int i=0; i<(1<<n); i++) 
            // i >> 1 gives us right shift of i by 1, which is basically i/2
            ans[i] = i^(i>>1);
        return ans;
    }
};