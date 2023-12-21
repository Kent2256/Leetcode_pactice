Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

class Solution {
public:
    void rec(auto &result,string sub,int i, int k){
        if(i<0) return;
        if(i==0 && k==0){
            result.push_back(sub);
            return;
        }
        if(i==k){
            rec(result,sub + '(', i-1,k);
        }
        else{
            rec(result,sub + '(', i-1,k);
            rec(result,sub + ')', i,k-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        rec(result,"",n,n);
        return result;
    }
};