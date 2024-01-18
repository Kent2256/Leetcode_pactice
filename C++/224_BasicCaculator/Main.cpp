Given a string s representing a valid expression, implement a basic calculator to evaluate it,
 and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, 
such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

class Solution {
public:
    int calculate(string s) {
        s.insert(0,"+(");
        s+=')';
        stack<int> out_sign;
        int prev=0;
        int ans =0;
        int sign = 1;
        out_sign.push(1);
        for(int i =0; i < s.length(); i ++){
            if(s[i] == ' ')continue;
            if(s[i] == '+' || s[i] == '-'){
                ans += prev * sign;
                prev=0;
                sign = s[i] == '+'? out_sign.top():-out_sign.top();
            }
            else if (s[i] == ')'){
                ans += prev * sign;
                prev=0;
                out_sign.pop();
                sign = out_sign.top();
            }
            else if (s[i] == '('){
                int x=i-1;
                while(s[x] == ' ')x--;
                if(s[x] == '-'){
                    out_sign.push(-out_sign.top());
                }
                else{
                    out_sign.push(out_sign.top());
                }
            }
            else{
                prev = prev*10 +(s[i] - '0');
            }
        }
        return ans;
    }
};

2147483640 + 55

"- (3 + (4 + 5))"


0
0
0
0
0
1
1
1
-3
-3
-8
-8
-10
-10
-10
-7
-7
-7
-7
-1
-1
7