#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.length() < ransomNote.length())return false;
        int cache[26]={0};
        for (char ch:magazine){
            cache[ch -'a']++;
        }
        for (char ch2:ransomNote){
            cache[ch2 - 'a']--;
            if(cache[ch2 - 'a'] < 0)return false;
        }
        return true;
    }
};

int main(){
    string ransomNote = "aa";
    string magazine = "aab";
    Solution sol;
    cout << sol.canConstruct(ransomNote, magazine) << endl;
}