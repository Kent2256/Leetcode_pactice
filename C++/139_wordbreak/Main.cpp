// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of 
// one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:
//             T f f T T f
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> map(s.length()+1, false);
        map[0] = true;
        for(int i=0; i<s.length();i++){
            if(map[i]){
                for(string word:wordDict){
                    if(i+word.length() <= s.length()+1){
                        int k = 0;
                        for(char ch:word){
                            if(ch != s[i+k]) break;
                            k++;
                        }
                        if(k==word.length())map[i + word.length()] = true;
                    }
                }
            }
        }
        return map.back();
    }
};