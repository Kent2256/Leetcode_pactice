// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// class Solution {
// public:
//     bool check_vec(vector<int> &table, vector<int> &window){
//         for(int i=0; i < table.size(); i++){
//             if(window[i] < table[i])return false;
//         }
//         return true;
//     }
//     string minWindow(string s, string t) {
//         int m = s.length();
//         int n = t.length();
//         if(m < n) return  "";
//         vector<int> table(58,0);
//         vector<int> window(58,0);
//         queue<int> pos;
//         //assign the table
//         for( char c:t){
//             table[c-'A']++;
//         }
//         int l=0,r=0,length = 0,min_length = INT_MAX;
//         int res_l=-1,res_r=-1;
//         while(r < m){
//             if(table[s[r] - 'A'])pos.push(r);
//             else if(pos.empty()){
//                 l++;
//                 r++;
//                 continue;
//             }
//             window[s[r] - 'A']++;
//             while(check_vec(table,window)){
//                 length = r-l + 1;
//                 if(length < min_length){
//                     min_length = length;
//                     res_l = l;
//                     res_r = r;
//                 }
//                 window[s[l] - 'A']--;
//                 pos.pop();
//                 l=pos.front();
//             }
//             r++;
//         }
//         string result ="";
//         if(res_l ==-1 || res_r == -1)return "";
//         else if(res_l <= res_r){
//             for(int k = res_l;k<=res_r;k++){
//                 result += s[k];
//             }
//             return result;
//         }
//         else{
//              return ""; 
//         }  
//     }
// };
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (char c : t) {
            map[c]++;
        }

        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

int main(){
    string s = "DADOBECODEBANC", t = "ABC";
    Solution sol;
    cout << sol.minWindow(s,t);
}