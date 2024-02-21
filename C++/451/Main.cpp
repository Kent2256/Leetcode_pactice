Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
class Solution {
public:
    string frequencySort(string s) {
        vector<int> mp(75,0);
        for( char c:s){
            mp[c-'0']++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i <= 74;i++){
            if(mp[i]!=0){
                pq.push({mp[i],i});
            }
        }
        string result="";
        while(!pq.empty()){
            auto[times,index] = pq.top();
            pq.pop();
            for(int i=0;i<times;i++){
                result+= '0'+index;
            }
        }
        return result;
    }
};

class Solution {
public:
    static bool sortcol1(const pair<char, int>& a, const pair<char, int>& b) 
    {
        return a.second > b.second; 
    }

    string frequencySort(string s) {
        vector<pair<char, int>> mp(256, {0, 0}); 
        for (char c : s) {
            mp[c].first = c;
            mp[c].second++;
        }
        
        sort(mp.begin(), mp.end(), sortcol1);
        
        string ans = "";
        for (const auto& p : mp) {
            int count = p.second;
            while (count--) {
                ans += p.first;
            }
        }
        return ans;
    }
};