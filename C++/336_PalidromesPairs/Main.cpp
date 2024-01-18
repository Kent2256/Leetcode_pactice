You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:

0 <= i, j < words.length,
i != j, and
words[i] + words[j] (the concatenation of the two strings) is a 
palindrome
.
Return an array of all the palindrome pairs of words.

You must write an algorithm with O(sum of words[i].length) runtime complexity.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]

class Solution {
public:
    bool ispalindrome(string s){
        if(s.length() == 1)return true;
        int l,r;
        l=s.length()/2-1;
        if(s.length()%2 == 0){
            r=l+1;
        }
        else{
            r=l+2;
        }
        while(l >=0 && r < s.length()){
            if(s[l] ==s[r]){
                l--;
                r++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int len = words.size();
        vecrot<vector<int>> result;
        for(int i=0; i < len;i ++){
            for(int k=0; k < len; k ++){
                if(k==i)continue;
                string sub_str = (words[i] + words[k]);
                if(ispalindrome(sub_str)){
                    result.push_back({i,k});
                }
            }
        }
        return result;
    }
};


class Solution {
public:

struct trie {
    trie* next[26];
    int ind=-1;
};

    void insert(trie* root, string word, int ind) {
        trie* trav=root;
        for(int j=word.size()-1; j>=0; --j) {
            int i=word[j]-'a';
            if(!trav->next[i]) trav->next[i]=new trie();
            trav=trav->next[i];
        }
        trav->ind=ind;
    }

    bool is_palindrome(string s, int si, int ei) {
        while(si < ei && s[si]==s[ei]) {
            ++si, --ei;
        }
        return si>=ei;
    }

    vector<int> search_words(trie* root) {
        stack<trie*> dfs;
        vector<int> result;
        dfs.push(root);
        while(dfs.size()) {
            trie* trav=dfs.top(); dfs.pop();
            if(trav->ind!=-1) result.push_back(trav->ind);
            for(int i=0; i<26; ++i) {
                if(trav->next[i]) dfs.push(trav->next[i]);
            }
        }
        return result;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        trie* root = new trie();
        for (int i = 0; i < words.size(); ++i) insert(root, words[i], i);

        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            trie* trav = root;
            int j=0;
            for(; j<w.size() && trav; ++j) {
                int ind=w[j]-'a';
                //Case1 word1[0,j-1] matched reversed word[trav->ind] and word1[j, w.size()-1] is a palindrome
                if(trav->ind!=-1 && trav->ind!=i && is_palindrome(w, j, w.size()-1)) result.push_back({i, trav->ind});  
                trav=trav->next[ind];
            }
            if(!trav) continue;
            //Case 2 and Case 3: word1 matched reversed part of word2 of completely, find all words that has matched suffix and check if the prefix are a palindrome.
            for(int ind:search_words(trav))
                if(i!=ind && is_palindrome(words[ind], 0, words[ind].size()-j-1)) result.push_back({i, ind}); 
        }

        return result;
    }
};

// // class Solution {
// // public:
// //     vector<vector<int>> palindromePairs(vector<string>& words) {
        
// //     }
// // };
//  class Solution {
//  public:
//      vector<vector<int>> palindromePairs(vector<string>& words) {
//          unordered_map<string, int> dict;
//          vector<vector<int>> ans;
//          // build dictionary
//          for(int i = 0; i < words.size(); i++) {
//              string key = words[i];
//              reverse(key.begin(), key.end());
//              dict[key] = i;
//          }
//          // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
//          if(dict.find("")!=dict.end()){
//              for(int i = 0; i < words.size(); i++){
//                  if(i == dict[""]) continue;
//                  if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
//              }
//          }

//          for(int i = 0; i < words.size(); i++) {
//              for(int j = 0; j < words[i].size(); j++) {
//                  string left = words[i].substr(0, j);
//                  string right = words[i].substr(j, words[i].size() - j);

//                  if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
//                      ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
//                  }

//                  if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
//                      ans.push_back({dict[right], i});
//                  }
//              }
//          }

//          return ans;        
//      }

//      bool isPalindrome(string str){
//          int i = 0;
//          int j = str.size() - 1; 

//          while(i < j) {
//              if(str[i++] != str[j--]) return false;
//          }

//          return true;
//      }

//  };

struct TrieNode
{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};
class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index)
    {
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr)
                continue;
            for (int j : cur->wordIndex)
            {
                if (i == j)
                    continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};