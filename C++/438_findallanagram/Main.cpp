#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int s1[26]= {0};
    int s2[26]= {0};
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int s_len = s.length();
        int p_len = p.length();
        if (s_len < p_len) return {};
        for(int i =0; i < p_len ;i ++){
            s1[p[i] - 'a']++;
            s2[s[i] - 'a']++;
        }
        cout << "check" << s1 << s2 <<endl;
        if(s1 == s2){
            cout << "check" << s1 << s2 <<endl;
            result.push_back(0);
        } 
        for(int i = 1; i <= s_len + p_len; i++){
            s2[s[i -1] - 'a']--;
            s2[s[i + p_len] - 'a'] ++;
            if(s1 == s2) result.push_back(i);
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int n=s.size(),m=p.size();
//         if(m>n)return {};
//         vector<int>p1(26,0),s1(26,0),ans;
//         for(int i=0;i<m;i++){
//             p1[p[i]-'a']++;
//             s1[s[i]-'a']++;
//         }
//         if(p1==s1)ans.push_back(0);
//         for(int i=m;i<(n);i++){
//             s1[s[i-m]-'a']--;
//             s1[s[i]-'a']++;
//             if(p1==s1){ans.push_back(i-m+1);}
//         }
//         return ans;
//     }
// };

int main(){
    string s = "abab", p = "ab";
    Solution sol;
    vector<int> res = sol.findAnagrams(s,p);
    for( int i:res){
        cout << i << ",";
    }
    cout << endl;
}