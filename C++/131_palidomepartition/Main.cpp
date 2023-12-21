// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:
// a,b,c
// ab, c
// a, bc
// abc
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindome(string substring){
        if (substring.length()==0)return false;
        int mid = substring.length()/2;
        int l,r=mid+1;
        if(substring.length()%2 ==0){
            if(substring[mid] != substring[mid-1]) return false;
            l = mid-2;
        }
        else l = mid - 1;
        while(l >= 0 && r <substring.length()){
            if(substring[l] != substring[r])return false;
            l--;
            r++;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& res, vector<string> subres, string s, string subs, int index){
        if( index == s.length()){
            if(!subs.empty())subres.push_back(subs);
            for( string substring: subres){
                if(!isPalindome(substring))return;
            }
            res.push_back(subres);
            return;
        }
        // if(isPalindome(subs+s[index])){
        //     subres.push_back(subs+s[index]);
        // }
        backtrack(res,subres,s,subs+s[index],index+1);
        subres.push_back(subs+s[index]);
        index++;
        if(index < s.length()){
            backtrack(res,subres,s,"",index);
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        backtrack(res,{},s,"",0);
        cout << "---------------------" << endl;
        return res;      
    }
};

// class Solution {
// private:
//     vector<vector<bool>> dp;
//     vector<vector<string>> ret;
//     vector<string> ans;
//     int n;
// public:
//     void dfs(string &s, int i){
//         if (i == n){
//             ret.push_back(ans);
//             return;
//         }
//         for (int j = i; j < n; j++){
//             if (dp[i][j]){
//                 ans.push_back(s.substr(i, j - i + 1));
//                 cout << "{" << i << "," << j  << "} " <<s.substr(i, j - i + 1) << endl;
//                 dfs(s, j + 1);
//                 ans.pop_back();
//             } 
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         n = s.length();
//         dp.assign(n, vector<bool>(n, true));

//         for (int j = 0; j < n; j++){
//             cout << "{" ;
//             for (int i = 0; i < j; i++){
//                 dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
//                 cout << dp[i][j] << ",";
//             }
//             cout << "}" << endl;
//         }
//         for(auto a1:dp){
//             cout << "{" ;
//             for( auto a2:a1){
//                 cout << a2 << ",";
//             }
//             cout << "}" << endl;
//         }
//         dfs(s, 0);
//         return ret;
//     }
// };

int main(){
    string s = "aabcc";
    Solution sol;
    sol.partition(s);
}