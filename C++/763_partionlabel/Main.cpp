You are given a string s.
We want to partition the string int o as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> intervals(26,vector<int>(2,-1));
        for(int i=0;i<s.length();i++){
            if(intervals[s[i] - 'a'][0] == -1){
                intervals[s[i] - 'a'][0] = i;
                intervals[s[i] - 'a'][1] = i;
            }
            else{
                intervals[s[i] - 'a'][1] = i;
            }
        }
        vector<vector<int>> intervals_exsist;
        for(auto vec:intervals){
            if(vec[0] != -1)intervals_exsist.push_back(vec);
        }
        sort(intervals_exsist.begin(),intervals_exsist.end());
        vector<vector<int>> res;
        res.push_back(intervals_exsist[0]);
        for(int i=1; i < intervals_exsist.size();i++){
            if(res.back()[1] > intervals_exsist[i][0]){
                res.back()[1] = max(res.back()[1],intervals_exsist[i][1]);
            }
            else{
                res.push_back(intervals_exsist[i]);
            }
        }
        vector<int> result;
        for(auto vec:res){
            result.push_back(vec[1]-vec[0]+ 1);
        }
        return result;
    }
};


class Solution {
public:
    
vector<int> partitionLabels(string s) {

    int startpoz[26];
    int endpoz[26];

    for(int i=0;i<26;i++){
        startpoz[i] = -1;
        endpoz[i] = -1;
    }

    for(int i=0;i<s.size();i++){

        if(startpoz[s[i] - 'a'] == -1)
            startpoz[s[i] - 'a']= i;

        endpoz[s[i] - 'a'] = i;
    }


    vector<int> lettersCount(s.size(), 0);

    for(int i=0;i<26;i++){
        if(startpoz[i] != -1)
            lettersCount[startpoz[i]]--;
        if(endpoz[i] != -1)
            lettersCount[endpoz[i]]++;
    }

    int startedLetters = 0;
    int addedValue= 0;

    vector<int> result;

    for(int i=0;i<s.size();i++){
        startedLetters+= lettersCount[i];

        if(startedLetters == 0){
            result.push_back(i+1 - addedValue);
            addedValue = i+1;
        }

    }

    return result;
}
};