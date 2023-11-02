/*Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map = {{'I',1},
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D',500},
                                        {'M',1000}};
        int res = 0;
        int prev = 0;
        for (char ch:s){
            if(map(s) > prev){
                res -= 2*prev;
            }
            res += map[ch];
            prev = map[ch];
        }
        return res;
    }
};