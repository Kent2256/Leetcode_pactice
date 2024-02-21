You are given the customer visit log of a shop represented by a 0-indexed 
string customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

 

Example 1:

Input: customers = "YYNY"
                o   1110
                c   3211
Output: 2      
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
Example 2:

Input: customers = "NNNNN"
                    11111
                    00000
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.
Example 3:

Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.
 

Constraints:

1 <= customers.length <= 105
customers consists only of characters 'Y' and 'N'.

class Solution {
public:
    int bestClosingTime(string customers) {
        int total_Y=0,total_N=0,n=customers.length();
        for(char c:customers){
            if(c=='Y')total_Y++;
            else total_N++;
        }
        if(total_Y == 0)return 0;
        if(total_N == 0)return n;
        int res=0,res_p=total_Y,left_N=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')total_Y--;
            else left_N++;
            int penalty = total_Y + left_N;
            if (res_p > penalty){
                res_p=penalty;
                res = i+1;
            }
        }
        return res;
    }
};
class Solution {
public:
    int bestClosingTime(string customers) {
        int max_score=0,cur_score=0,res=0;
        for(int i=0;i<customers.length();i++){
            if(customers[i]=='Y')cur_score++;
            else cur_score--;
            if(max_score < cur_score){
                max_score = cur_score;
                res = i+1;
            }
        }
        return res;
    }
};
class Solution {
public:
    int bestClosingTime(string cus) {
        int mx =0, ret = -1, curs=0;
        for(int i=0;i<cus.size();i++){
            curs+=cus[i]=='Y'?1:-1;
            if(curs>mx){
                mx = curs;
                ret = i;
            }
        }
        return ret+1;
    }
};