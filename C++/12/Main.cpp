Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int thousands = num/1000;
        num%=1000;
        for(int i=0;i<thousands;i++)result += 'M';

        int hundred = num/100;
        num%=100;
        if(hundred == 9){
            result += 'CM';
        }
        else if(hundred == 4){
            result += 'CD';
        }
        else if(hundred >= 5){
            result += 'D';
            hundred -= 5;
            for(int i=0;i<hundred;i++)result += 'C';
        }
        else{
            for(int i=0;i<hundred;i++)result += 'C';
        }

        int ten = num/10;
        num%=10;
        if(ten == 9){
            result += 'XC';
        }
        else if(ten == 4){
            result += 'XL';
        }hundredten
        else if(ten >= 5){
            result += 'L';
            ten -= 5;
            for(int i=0;i<ten;i++)result += 'X';
        }
        else{
            for(int i=0;i<ten;i++)result += 'X';
        }

        int one = num;
        if(one == 9){
            result += 'IX';
        }
        else if(one == 4){
            result += 'IV';
        }
        else if(one >= 5){
            result += 'V';
            one -= 5;
            for(int i=0;i<one;i++)result += 'I';
        }
        else{
            for(int i=0;i<one;i++)result += 'I';
        }

        return result;
    }
};