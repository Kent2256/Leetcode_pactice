// Given two strings text1 and text2, return the length of their longest common subsequence. 
// If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some 
// characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.
//   c b a c e 
// a 3 3 3 2 1
// c 2 2 2 2 1
// e 1 1 1 1 1

//   a b c d e 
// a 3 2 2 1 1
// c 2 2 2 1 1
// e 1 1 1 1 1
14,13,13,13,12,12,12,12,12,12,12,12,12,12,12,12,11,11,11,11,11,11,10,10,10,10,10,10,10,10,10,10,10,9,9,9,8,7,6,5,5,4,3,2,1,0,                                        
"bmvcnwrmxcfcxabkxcvgbozmpspsbenazglyxkpibgzq"
"bmpmlstotylonkvmhqjyxmnqzctonqtobahcrcbibgzgx"
bm
14,13,12,12,12,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,10,9,9,9,8,8,7,7,7,7,7,7,6,5,5,5,4,3,2,2,1,0,
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(), n=text2.length();
        vector<vector<int>> grid(m+1,vector<int>(n+1,0));
        for(int i = m-1; i>=0;i--){
            for(int k=n-1;k>=0;k--){
                if(text1[i]==text2[k]){
                    grid[i][k] = grid[i+1][k+1]+1;
                }
                else{
                    grid[i][k] = max(grid[i+1][k],grid[i][k+1]);
                }
            }
        }
        return grid[0][0];
    }
};

class Solution {
public:
     int spaceOptimise(string text1,string text2){
        vector<int> curr(text2.length()+1,0);
        vector<int> next(text2.length()+1,0);
        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
                    int ans;
                    if(text1[i]==text2[j])
                        ans=1+next[j+1];
                    else
                        ans=max(curr[j+1],next[j]);
                    curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return spaceOptimise(text1,text2);
    }
};


13,13,13,13,12,12,12,12,12,12,12,12,12,12,12,12,11,11,11,11,11,11,10,10,10,10,9,9,9,9,9,9,9,9,9,9,8,7,6,5,5,4,3,2,1,0,
12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,11,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,9,9,9,8,7,6,5,5,4,3,2,1,0,
12,12,12,12,12,12,12,12,12,12,12,12,12,11,11,11,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,9,9,9,8,7,6,5,5,4,3,2,1,0,
12,12,12,12,12,12,12,12,12,12,12,12,12,11,11,11,10,10,10,10,10,10,10,9,9,9,9,9,9,8,8,8,8,8,8,8,8,7,6,5,5,4,3,2,1,0,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,10,10,10,10,9,9,9,9,8,8,8,8,8,8,8,8,8,8,8,7,6,5,5,4,3,2,1,0,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,10,10,10,10,9,9,9,9,8,8,8,8,8,8,8,8,8,8,8,7,6,5,5,4,3,2,1,0,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,10,10,10,10,9,9,9,9,8,8,8,8,8,8,8,8,8,8,7,7,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,8,8,8,8,8,8,8,8,8,8,7,7,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8,8,8,7,7,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,7,7,6,6,6,6,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,7,7,6,6,6,6,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,7,6,6,6,6,6,6,5,5,4,3,2,1,0,
11,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,6,6,6,6,6,6,5,4,4,4,3,2,1,0,
11,10,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,6,6,6,6,6,6,5,4,4,4,3,2,1,0,
11,10,9,9,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,6,6,6,6,6,6,5,4,4,4,3,2,1,0,
11,10,9,9,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,5,5,5,5,5,5,4,4,4,3,2,1,0,
11,10,9,9,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,5,5,5,5,5,5,4,4,4,3,2,1,0,
11,10,9,9,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
10,10,9,9,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
10,10,9,9,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
10,10,9,9,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
9,9,9,8,8,8,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
9,9,9,8,8,8,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
9,9,9,8,8,8,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
8,8,8,8,8,8,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
8,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,4,4,3,3,2,1,0,
7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,4,4,4,4,4,4,3,3,3,2,1,0,
7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,4,4,4,4,4,4,3,3,3,2,1,0,
7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4,3,3,3,2,1,0,
7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,2,1,0,
7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,2,2,1,0,
7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1,1,1,0,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1,1,1,0,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1,1,1,0,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1,1,0,0,
5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1,1,0,0,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1,1,0,0,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1,1,0,0,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,