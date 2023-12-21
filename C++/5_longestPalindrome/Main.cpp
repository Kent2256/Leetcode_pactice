
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
// isPalindrome string left right return string

class Solution {
public:
    string isPalindrome(string s, int left, int right){
        if( left < 0 || right >= s.length || s[left] != s[right]) return s.substr(left+1,(right-left)-1);
        return(isPalindrome(s, left - 1, right + 1));
    }
    string longestPalindrome(string s) {
        int m = s.length();
        string temp,res;
        for(int i=0; i<m-1; i++){
            int l=i;
            while(s[i] == s[i+1])i++;
            int r=i+1;
            temp = isPalindrome(s,i,);
            if (temp.length() > res.length()) res = temp;
        }
        return res;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int st=0, n=s.length(), max_len=1;
        for(int i=0 ; i<n ; i++){
            int l=i, r=i;
            while(r<n-1 && s[r]==s[r+1]){
                r++;
            }
            i=r;
            while(l>0 && r<n-1 && s[l-1]==s[r+1]){
                l--;r++;
            }
            if(max_len < r-l+1){
                st=l;
                max_len=r-l+1;
            }
        }
        return s.substr(st, max_len);
    }
};