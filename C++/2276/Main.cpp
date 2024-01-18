Given an empty set of intervals, implement a data structure that can:

Add an interval to the set of intervals.
Count the number of integers that are present in at least one interval.
Implement the CountIntervals class:

CountIntervals() Initializes the object with an empty set of intervals.
void add(int left, int right) Adds the interval [left, right] to the set of intervals.
int count() Returns the number of integers that are present in at least one interval.
Note that an interval [left, right] denotes all the integers x where left <= x <= right.

 

Example 1:

Input
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
Output
[null, null, null, 6, null, 8]

Explanation
CountIntervals countIntervals = new CountIntervals(); // initialize the object with an empty set of intervals. 
countIntervals.add(2, 3);  // add [2, 3] to the set of intervals.
countIntervals.add(7, 10); // add [7, 10] to the set of intervals.
countIntervals.count();    // return 6
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 7, 8, 9, and 10 are present in the interval [7, 10].
countIntervals.add(5, 8);  // add [5, 8] to the set of intervals.
countIntervals.count();    // return 8
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 5 and 6 are present in the interval [5, 8].
                           // the integers 7 and 8 are present in the intervals [5, 8] and [7, 10].
                           // the integers 9 and 10 are present in the interval [7, 10].
 

Constraints:

1 <= left <= right <= 109
At most 105 calls in total will be made to add and count.
At least one call will be made to count.

class CountIntervals {
public:
    vector<vector<int>> intervals;
    int size=0;
    CountIntervals() { 
    }
    
    void add(int left, int right) {
        if(intervals.empty()){
            intervals.push_back({left,right});
            size+=(right-left+1);
            return;
        }
        if(left > intervals.back()[1] + 1){
            intervals.push_back({left,right});
            size += (right-left+1);
            return;
        }
        else if(right < intervals[0][0]-1){
            intervals.insert(intervals.begin(), {left,right});
            size +=(right-left+1);
            return;
        }
        size=0;
        vector<vector<int>> new_one;
        intervals.push_back({left,right});
        sort(intervals.begin(),intervals.end());
        new_one.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(new_one.back()[1]+1 >= intervals[i][0]){
                new_one.back()[0] = min(new_one.back()[0],intervals[i][0]);
                new_one.back()[1] = max(new_one.back()[1],intervals[i][1]);
            }
            else{
                new_one.push_back(intervals[i]);
            }
        }
        for(auto temp:new_one)size+=(temp[1]-temp[0]+1);
        intervals = new_one;
    }
    
    int count() {
        return size;
    }
};