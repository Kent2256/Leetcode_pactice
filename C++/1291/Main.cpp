An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9

class Solution {
public:
    vector<int> stand = {1,
                         12,
                         123,
                         1234,
                         12345,
                         123456,
                         1234567,
                         12345678,
                         123456789};
    vector<int> comp = {1,
                        11,
                        111,
                        1111,
                        11111,
                        111111,
                        1111111,
                        11111111};
    vector<int> sequentialDigits(int low, int high) {
        if(low >stand[8]) return {};
        int low_count = 0,low_temp = low;
        while(low_temp/10){
            low_count++;
            low_temp/=10;
        }
        int start = stand[low_count];
        for(int i=0;i < 8-low_count;i++){
            if(start < low)start+= comp[low_count];
            else break;
        }
        if(start < low) start = stand[++low_count];
        cout << start;
        vector<int> result;
        while(start <= high){
            result.push_back(start);
            if(low_count==8)break;
            if(start%10 == 9){
                start =stand[++low_count];
            }
            else{
                start+= comp[low_count];
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if(low > 123456789) return {};
        queue<int> q;
        for(int i=1; i<=9;i++)q.push(i);
        vector<int> ret;
        while(!q.empty()){
            f=q.front();
            q.pop();
            if(f>= low && f<=high){
                ret.push_back(f);
            }
            if(f>high)break;
            q.push(f*10+f+1);
        }
        return ret;
    }
};