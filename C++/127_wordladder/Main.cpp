A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words 
beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

["hot","dot","tog","cog"]
cog
Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique."

class Solution {
public:
    bool adjacent(string word1, string word2){
        int count = 0;
        for(int i=0; i<word1.length();i++){
            if(word1[i]!=word2[i]) count++;
        }
        return count==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end()) return 0;
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<string> wordList_set(words.begin(),words.end());
        int res =1;
        vector<int> visited(wordList.size(),0);
        queue<int> container;
        for(int i=0; i< wordList_set.size();i++){
            if (adjacent(beginWord,wordList_set[i])){
                container.push(i);
                visited[i] = 1;
            }
        }
        container.push(-1);
        while(container.size() >= 1){
            if(container.front() == -1){
                res++;
                container.push(-1);
                container.pop();
                if(container.front() == -1)return 0;
            }
            string word = wordList_set[container.front()];
            container.pop();
            if(word == endWord){
                res++;
                return res;
            }
            for(int i=0; i< wordList_set.size();i++){
                if (visited[i])continue;
                if (adjacent(word,wordList_set[i])){
                    container.push(i);
                    visited[i] = 1;
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // return ladderLengthByGraph(beginWord, endWord, wordList);
        return ladderLengthBySet(beginWord, endWord, wordList);
    }

    int ladderLengthBySet(string beginWord, string endWord, vector<string>& wordList) {
        // build a set
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0;
        if (words.find(beginWord) != words.end()) words.erase(beginWord);
        // do BFS
        queue<pair<string, int>> q;
        q.push(pair<string, int>({beginWord, 1}));
        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endWord) {
                return step;
            }
            for (int i = 0; i < word.length(); i++) {
                string new_word = word;
                for (int j = 0; j < 26; j++) {
                    new_word[i] = 'a' + j;
                    if (words.find(new_word) != words.end()) {
                        q.push(pair<string, int>({new_word, step + 1}));
                        words.erase(new_word);
                    }
                }
            }
        }
        return 0;
    }

    int ladderLengthByGraph(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), start = -1, end = -1;
        // check begin word
        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord) start = i;
            else if (wordList[i] == endWord) end = i;
        }
        if (end == -1) return 0;
        if (start == -1) {
            wordList.insert(wordList.begin(), beginWord);
            start = 0;
            end ++;
            n ++;
        }
        // build graph
        vector<vector<int>> G(n, vector<int>());
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (isConnected(wordList[i], wordList[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        // do BFS, calculate steps
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        q.push(pair<int, int>({start, 1}));
        visited[start] = true;
        while (!q.empty()) {
            int curr = q.front().first;
            int step = q.front().second;
            q.pop();
            if (curr == end) {
                return step;
            }
            for (int i = 0; i < G[curr].size(); i++) {
                int next = G[curr][i];
                if (visited[next]) continue;
                visited[next] = true;
                q.push(pair<int, int>({next, step + 1}));
            }
        }
        return 0;
    }

    bool isConnected(string& s, string& t) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) cnt ++;
            if (cnt == 2) return false;
        }
        return cnt == 1;
    }
};