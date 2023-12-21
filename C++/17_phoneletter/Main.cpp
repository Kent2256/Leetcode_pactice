class Solution {
public:
    unordered_map <char,vector<string>> map = {
        {'2',{"a","b","c"}},
        {'3',{"d","e","f"}},
        {'4',{"g","h","i"}},
        {'5',{"j","k","l"}},
        {'6',{"m","n","o"}},
        {'7',{"p","q","r","s"}},
        {'8',{"t","u","v"}},
        {'9',{"w","x","y","z"}}};
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if(len == 0){
            return {};
        }
        vector<vector<string>> res;
        res.resize(len);
        for( string ch:map[digits[0]]){
            res[0].push_back(ch);
        }
        for( int i=1; i < len ;i++){
            for( string ch: map[digits[i]]){
                for( string st: res[i-1]){
                    res[i].push_back((st + ch));
                }
            }
        }
        return res[len-1];
    }
};