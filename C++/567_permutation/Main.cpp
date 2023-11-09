// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int> s1_table(26,0);
        vector<int> slide_table(26,0);
        for(char c:s1){
            s1_table[c-'a']++;
        }
        //initial s2_table
        for (int i=0; i < m - 1;i++){
            slide_table[s2[i]-'a']++;
        }
        //sliding window
        int l=0,r=l+s1.length()-1;
        while(r < n){
            slide_table[s2[r]-'a']++;
            if(s1_table == slide_table) return true;
            slide_table[s2[l]-'a']--;
            l++;
            r++;
        }
        return false;
    }
};

int main(){
    vector<int> s1(26,0);
    s1['b'-'a'] = 1;
    s1['c'-'a'] = 1;
    vector<int> s2(26,0);
    s2['c'-'a'] = 1;
    s2['b'-'a'] = 1;
    if(s1 == s2){
        cout << "check right";
    }
}
 