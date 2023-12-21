Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int i=1;
        res.push_back(intervals[0]);
        while(i<intervals.size()){
            if(res.back()[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
            i++;
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(),i.end());
        vector<vector<int>> res;
        res.push_back(i[0]);
        for(int j=1;j<i.size();j++){
            vector<int> b = res.back();
            if (i[j][0]<=b[1]){
                res.pop_back();
                //b[0]=min(b[0],i[j][0]);
                b[1]=max(b[1],i[j][1]);
                res.push_back(b);
            } else {
                res.push_back(i[j]);
            }
        }
        return res;
    }
};