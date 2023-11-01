#include <iostream>
#include <string>
#include <math.h>

using namespace std;
class Solution {
public:
    // int checkPalindrome(string s, int start, int end){
    //     if (start < 0 || end >= s.length()){
    //         return 1;
    //     }
    //     if(s[start] != s[end]){
    //         return (end-start) + 1;
    //     }
    //     else{
    //         return checkPalindrome(s, start-1,end+1);
    //     }
    // }
    // int longestPalindrome(string s) {
    //     int n = s.length();
    //     if(n == 0){
    //         return 0;
    //     }
    //     int result = 0;
    //     for( int i =0; i < n; i++){
    //         int temp = max(checkPalindrome(s,i,i), checkPalindrome(s,i,i+1));
    //         result = max(temp,result);
    //     }
    //     return result;
    // }
    int longestPalindrome(string s) {
        int cache[256] = {0};
        int single_flag = 0;
        int result = 0;
        for ( char ch: s){
            cache[ch]++;
        }
        for (int num:cache){
            if (num%2 == 1 && single_flag == 0){
                single_flag++;
            }
            result += (num/2)*2;
        }
        return result + single_flag;
    }
};

int main(){
    string s = "abccccdd";
    string s2 = "a";
    string s3 = "AAAAA";
    Solution sol;
    cout << sol.longestPalindrome(s) << " " << sol.longestPalindrome(s2) << " " << sol.longestPalindrome(s3) << endl;
}