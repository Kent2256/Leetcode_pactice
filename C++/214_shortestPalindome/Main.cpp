You are given a string s. You can convert s to a 
palindromeby adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.

class Solution {
public:
    bool isPalindome(string s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        int end=s.length()-1;
        for(;end>=0;end--){
            if(isPalindome(s,0,end))break;
        }
        string res=s.substr(end+1);
        reverse(res.begin(),res.end());
        res+=s;
        return res;
    }
};

class Solution {
public:
       string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        vector<int> lps(n_new, 0);
        int t=0;
        for(int i=1;i<n_new;i++){
            t=lps[i-1];
            while(t>0 && s_new[i]!=s_new[t]){
                t=lps[t-1];
            }
            if(s_new[i]==s_new[t]){
                ++t;
            }
            lps[i]=t;
        }
        return rev.substr(0,n-lps[n_new-1]) + s;
        
    }
};
"aacecaaa"
a a c e c a a a # a a a c e c a a
0,1,0,0,0,1,2,2,0,1,2,2,3,4,5,6,7,
"abcd"
a b c d # d b c a
0,0,0,0,0,0,0,0,1,