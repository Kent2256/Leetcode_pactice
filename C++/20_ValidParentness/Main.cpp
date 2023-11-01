#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
class Solution {
public:
    bool isValid(string s) {
        unordered_map < char, char > bracket = { {')','('}, {']','['}, {'}','{'}};
        string result = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                result.push_back(s[i]);
                continue;
            }
            if (bracket.find(s[i]) != bracket.end()){
                if(result.empty() || result[result.size() - 1] != bracket[s[i]]){
                    return false;
                }else{
                    result.pop_back();
                }
            }
        }
        return result.size() == 0;
    }
};
*/
class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' && ch == '(') ||  (it == ']' && ch == '[') || (it == '}' && ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
};

int main(){
    string s = "()";
    Solution sol;
    cout << sol.isValid(s) << endl;
};