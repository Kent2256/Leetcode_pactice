#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, temp = 0, prev = -1;
        for( int x: prices){
            if( prev == -1){
                prev = x;
                continue;
            }
            temp += x - prev;
            if (temp < 0){
                temp = 0;
                prev = x;
            }else{
                if (temp > result){
                    result = temp;
                }
                prev = x;
            } 
        }
        return result;
    }
};
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int profit=0,tempprofit;
        int len=prices.size();
        for(int i=1;i<len;i++){
            
            tempprofit=prices[i]-minprice;
            profit=max(tempprofit,profit);
            minprice=min(minprice,prices[i]);
        }
        
        return profit;
            
    }
};*/
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
};
