You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. 
Each element can be selected at most once.

Return the length of the longest palindrome that you can create. 
If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> map;
        int res=0;
        bool pair=false;
        int palindrome_set =0;
        for(int i=0;i<words.size();i++){
            if(map.find(words[i])!=map.end() && map[words[i]] > 0){
                map[words[i]]--;
                res+=4;
                if(!pair)pair=true;
                if(words[i][0]==words[i][1])palindrome_set--;
            }
            else{
                if(words[i][0]==words[i][1])palindrome_set++;
                string rev="";
                rev+=words[i][1];
                rev+=words[i][0];
                map[reb]++;
            }
        }
        if(!pair){
            return palindrome_set>0?2:0;
        }
        else{
            return palindrome_set>0?res+2:res;
        }
    }
};

class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        int n = w.size();

        unordered_map<string, int>mp;

        for(int i=0; i<n; i++)mp[w[i]]++;

        int ans = 0;
        bool f = 0;

        for(auto it = mp.begin(); it != mp.end(); it++ ){
            string val = it->first;
            // cout<<val[0]<<endl;
            // cout<<val[1]<<endl;
            string rev = val;//val[1] + val[0];//val.reverse(val.begin(), val.end());
            reverse(rev.begin(), rev.end());
            // cout<<val<<" "<<rev<<endl;

            if(val[0] == val[1] && f == 0){
                ans += 2 * it->second;
                if(it->second % 2 == 1)f = 1;
            }
            else if(val[0] == val[1] && f == 1){
                ans += 4 * (mp[val] / 2);
            }
            else if(mp.find(rev) == mp.end()){
                // cout<<rev<<endl;
                continue;
            }
            else{
                ans += 2 * min(mp[val], mp[rev]);
            }
        }

        return ans;

    }
};