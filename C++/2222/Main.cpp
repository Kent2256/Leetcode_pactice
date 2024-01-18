You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and
s[i] = '1' denotes that the ith building is a restaurant.
As a city official, you would like to select 3 buildings for random inspection. 
However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" 
which is not allowed due to having two consecutive buildings of the same type.
Return the number of valid ways to select 3 buildings.

 

Example 1:

Input: s = "001101"
Output: 6
Explanation: 
The following sets of indices selected are valid:
- [0,2,4] from "001101" forms "010"
- [0,3,4] from "001101" forms "010"
- [1,2,4] from "001101" forms "010"
- [1,3,4] from "001101" forms "010"
- [2,4,5] from "001101" forms "101"
- [3,4,5] from "001101" forms "101"
No other selection is valid. Thus, there are 6 total ways.
Example 2:

Input: s = "11100"
Output: 0
Explanation: It can be shown that there are no valid selections.
 

Constraints:

3 <= s.length <= 105
s[i] is either '0' or '1'.


class Solution {
public:
    void rec(string s,vector<int> &sub_s,int i, int& count){
        if(i>s.length())return;
        if(sub_s.size()==3){
            count++
            return;
        }
        if(sub_s.empty() || sub_s.back() != s[i]-'0'){
            sub_s.push_back(s[i] - '0');
            rec(s,sub_s,i+1,count);
            sub_s.pop_back();
        }
        rec(s,sub_s,i+1,count);
    }
    long long numberOfWays(string s) {
        vector<int> sub_s;
        int count=0;
        rec(s,sub_s,0,count);
        return count;
    }
};

class Solution {
public:
    long long numberOfWays(string s) {
        long int cnt0 = 0, cnt1 = 0;
        int n = s.length();
        for(char ch: s){
            if(ch=='1'){cnt1++;}
            else{cnt0++;}
        }
        long int cnt0SoFar = 0, cnt1SoFar = 0;
        long long ans = 0;
        for(char ch : s){
            if(ch=='1'){
                ans = ans + (cnt0SoFar*cnt0);
                cnt1--;
                cnt1SoFar++;
            }else{
                ans = ans + (cnt1SoFar*cnt1);
                cnt0--;
                cnt0SoFar++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    #define ll long long
    
    ll dp[(int)1e5+3][4][3];
    ll f(string& s, int i, int count, int prev) {
        if(count == 0) return 1;
        
        if(i == s.size()) return 0;
        
        ll& st = dp[i][count][prev+1];
        
        if(st != -1) return st;
        
        ll take = 0;
        if(prev != s[i]-'0') {
            take += f(s, i+1, count-1, s[i]-'0');
        }
        
        ll notTake = f(s, i+1, count, prev);
        
        return st = take+notTake;
    }
    
    long long numberOfWays(string s) {
        memset(dp, -1, sizeof dp);
        return f(s, 0, 3, -1);
    }
};