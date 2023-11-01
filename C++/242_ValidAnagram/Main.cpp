#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> map;
        for (char ch: s){
            if(map.find(ch) != map.end()){
                map[ch]++;
            }else{
                map[ch] = 1;
            }
        }
        for (char ch:t){
            if(map.find(ch) == map.end()){
                return false;
            }else{
                map[ch]--;
                if (map[ch] < 0) return false;
            }

        }
        return true;
    }
};

/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())return false;
        int cache[26] = {0};
        for (char ch: s){
            cache[ch - 'a']++;
        }
        for (char ch:t){
            cache[ch - 'a']--;
            if (cache[ch - 'a'] < 0) return false;
        }
        return true;
    }
};*/

int main(){
    string s = "anagram", t = "nagaram";
    Solution sol;
    cout << sol.isAnagram(s,t) << endl;
};