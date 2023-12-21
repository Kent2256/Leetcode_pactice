Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
park
spake
4
3
class Solution {
public:
    int rec(string& s, string& t , vector<vector<int>>& dp, int i, int j){
        if(i == s.length()) return t.length()-j;
        if(j == t.length()) return s.length()-i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            dp[i][j] = rec(s,t,dp,i+1,j+1);
        }
        else{
            dp[i][j] = 1 + min(min(rec(s,t,dp,i+1,j+1),rec(s,t,dp,i+1,j)),rec(s,t,dp,i,j+1));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(),n =word2.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(word1,word2,dp,0,0);
    }
};

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.