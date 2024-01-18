You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


class Solution {
public:
    int characterReplacement(string s, int k) {
        
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int s_len = s.length();
        if(s_len == 1)return 1;
        int map[26] = {0};
        int max_f = 0,l=0,r=0,length=0,max_length=0;
        while(r <s_len){
            length = r - l + 1;
            map[s[r] - 'A']++;
            max_f = max(map[s[r]-'A'], max_f);
            if(length - max_f <= k){
                max_length= max(max_length,length);
                r++;
            }
            else{
                if(length - max_f > k){
                    map[s[l] -'A']--;
                    l++;
                }
                r++;
            }
        }
        return max_length;

    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int low = 0;
        int high = 0;
        int maxCount = 0;
        int res = 0;
        while(high < s.size()){
            ++count[s[high]-'A'];
            maxCount = max(maxCount,count[s[high]-'A']);
            if(high-low+1-maxCount >k){
                --count[s[low]-'A'];
                ++low;
            }else{
                res = max(res,high-low+1);
            }
            ++high;
        }
        return res;
    }
};