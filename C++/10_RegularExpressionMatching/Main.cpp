Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

class Solution {
public:
    void dfs(string& s, string& p, auto& dp, int i, int j){
        if(j==p.length())return;
        if(i==s.length()&&dp[s.length()-1][p.length()] == false){
            int next = j;
            while(next!=p.length()){
                if(p[next]!='*'){
                    p[next] = '#';
                }
                next++;
            }
            dfs(s,p,dp,i-1,j);
            return;
        }
        if(dp[i][j]==true)return;
        if(p[j]=='.' || s[i]==p[j]){
            dp[i][j] = true;
            dfs(s,p,dp,i+1,j+1);
        }
        else if(p[j]=='*' && j!=0){
            dfs(s,p,dp,i,j-1);
            dp[i][j] = dp[i][j-1];
            if(dp[i][j] == true){
                dfs(s,p,dp,i+1,j);
            }
            dfs(s,p,dp,i,j+1);
        }
        else if(s[i]!=p[j] && j+1!=p.length() && p[j+1] == '*'){
            if(i==0 || dp[i-1][j] ==false){
                dp[i][j] = dp[i][j+1] = true;
            }
            dfs(s,p,dp,i,j+2);
        }
        return;
    }
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m,vector<bool>(n,false));
        dfs(s,p,dp,0,0);
        for(auto c1:dp){
            for(auto c2:c1){
                cout << c2 << ",";
            }
            cout << endl;
        }
        return dp[m-1][n-1];
    }
};
     m i s * i s * p * .
m    1,0,0,0,0,0,0,0,0,0,
i    0,1,0,0,0,0,0,0,0,0,
s    0,0,1,0,0,0,0,0,0,0,
s    0,0,1,1,0,0,0,0,0,0,
i    0,0,1,1,1,0,0,0,0,0,
s    0,0,1,1,0,1,0,0,0,0,
s    0,0,1,1,0,1,1,1,1,1,
i    0,0,1,1,1,1,1,1,1,1,
p    0,0,1,1,0,1,1,1,0,0,
p    0,0,1,1,0,1,1,1,1,1,
i    0,0,1,1,1,1,1,1,1,1,

  m i s * i s * p * .
m 1,0,0,0,0,0,0,0,0,0,
i 0,1,0,0,0,0,0,0,0,0,
s 0,0,1,0,0,0,0,0,0,0,
s 0,0,1,1,0,0,0,0,0,0,
i 0,0,0,0,1,0,0,0,0,0,
s 0,0,0,0,0,1,0,0,0,0,
s 0,0,0,0,0,1,1,0,0,1,
i 0,0,0,0,0,0,0,0,0,1,
p 0,0,0,0,0,0,0,0,0,0,
p 0,0,0,0,0,0,0,0,0,0,
i 0,0,0,0,0,0,0,0,0,0,