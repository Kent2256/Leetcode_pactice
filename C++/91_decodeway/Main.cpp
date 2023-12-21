A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above 
(there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
//    11  1 combine 
//    1 1 1 add new one
//    1  11  
0=>1
1=>1
11=>2
111

"1" ==> 1i
"11" ==> 1+1
"111"==> 1+1+1
Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:
"26" ==> 2
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

class Solution {
public:
    int numDecodings(string s) {
        int m = s.length();
        vector<int> res(2,1);
        char prev = s[0];
        if(prev =='0') return 0;
        for(int i=1;i<m;i++){
            if(prev != '0'){
                if(s[i] == '1' || s[i] == '2'){
                    if(prev == '1' || prev =='2')res.push_back(res[i]+res[i-1]);
                    else res.push_back(res[i]);
                }
                else if(s[i] == '0'){
                    if(prev != '1' && prev != '2')return 0;
                    res.push_back(res[i-1]);
                }
                else if(s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'){
                    if(prev == '1' || prev =='2')res.push_back(res[i]+res[i-1]);
                    else res.push_back(res[i]);
                }
                else{
                    res.push_back(res[i]);
                }
                prev = s[i];
            }
            else{
                if(s[i] == '0') return 0;
                res.push_back(res[i]);
                prev = s[i];
            }
        } 
        return res.back();
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1]; // dp[i] = decode(i) // solve from i
        dp[n] = 1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0')dp[i]=0;
            else {
                dp[i] = dp[i+1];
                if(i+1<n && (s[i]=='1' || s[i]=='2'&&s[i+1]>='0'&&s[i+1]<'7'))
                    dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
}