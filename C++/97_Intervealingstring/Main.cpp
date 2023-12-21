Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.



Example 1:

3 5 7 1
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 
"aa" "ab" "aaba"
Follow up: Could you solve it using only O(s2.length) additional memory space?
class Solution {
public:
    bool solve(auto &dp, string &s1,string &s2, string &s3,int j,int k){
        if(j+k == s3.length()) return true;
        if( dp[j][k] == true) return true;
        bool res = false;
        if(j < s1.length() && k < s2.length() && s1[j] == s3[j+k] && s2[k]==s3[j+k]){
            res = (solve(dp,s1,s2,s3,j+1,k)||solve(dp,s1,s2,s3,j,k+1));
        }
        else if (j < s1.length() && s1[j] == s3[j+k]){
            res = solve(dp,s1,s2,s3,j+1,k);
        }
        else if(k < s2.length() && s2[k]==s3[j+k]){
            res = solve(dp,s1,s2,s3,j,k+1);
        }
        return dp[j][k] = res;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        //vector<vector<bool>> dp(101,vector<bool>(101,false));
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        return solve(dp,s1,s2,s3,0,0);
    }        
};

class Solution {
    int dp[101][101];
    bool solve(string &s1, string &s2, string &s3,int i,int j)
    {
        if(i == s1.length() && j == s2.length() && i+j == s3.length()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool result = false;
        
        if(i < s1.length() && j < s2.length() && s1[i] == s3[i+j] && s2[j] == s3[i+j])
        {
            result = (solve(s1,s2,s3,i+1,j) || solve(s1,s2,s3,i,j+1));
        }
        else if(i < s1.length() && s1[i] == s3[i+j])
        {
            result = solve(s1,s2,s3,i+1,j);
        }
        else if(j < s2.length() && s2[j] == s3[i+j])
        {
            result = solve(s1,s2,s3,i,j+1);
        }
        return dp[i][j] = result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
      if(s1.length() + s2.length() != s3.length()) return false;
      memset(dp,-1,sizeof(dp));
      return solve(s1,s2,s3,0,0);
    }
};