#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
public:

    string addBinary(string a, string b) {
        string result;
        int stoarge = 0;
        int a_len = a.length()-1, b_len = b.length()-1;
        while(a_len >= 0 || b_len >=0 || stoarge){
            if(a_len >= 0){
                stoarge += (a[a_len--] - '0');
            }
            if(b_len >=0){
                stoarge += (b[b_len--]- '0');
            }
            result += stoarge%2 + '0';
            stoarge/=2;    
        }
        reverse(result.begin(),result.end()); 
        return result;
    }
};

int main(){
    string a ="11",b="1";
    Solution sol;
    cout << sol.addBinary(a,b) << endl;
}


