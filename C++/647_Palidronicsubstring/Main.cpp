Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

class Solution {
public:
    int countSubstrings(string s) {
        int m=s.length();count=0;
        for(int i=0;i<m;i++){
            count++;
            int l=i,r=i+1;
            while(s[i] == s[r]){
                count++;
                r++;
            }
            while(l>0 && r<n-1 && s[l-1]==s[r+1]){
                l--;r++;
                count++;
            }
        }
        return count;
    }
};
 