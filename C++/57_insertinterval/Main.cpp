#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        printVector(intervals);
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size();i++){
            printVector(result);
            if( result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;    
    }
    void printVector(vector<vector<int>>& nums){
        for( vector<int> sub : nums){
            cout << "{" << sub[0] <<"," << sub[1] << "}";
        }
        cout << endl;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        while(i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
int main(){
    vector<vector<int>> internal = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    Solution sol;
    vector<vector<int>> res = sol.insert(internal,newInterval);
    sol.printVector(res);
}