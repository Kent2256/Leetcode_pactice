You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at 
righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.

You are also given an integer array queries. The answer to the jth query is the size of the smallest 
interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
Return an array containing the answers to the queries.


Example 1:

Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
Output: [3,3,1,4]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
Example 2:

Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
Output: [2,-1,4,6]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
- Query = 19: None of the intervals contain 19. The answer is -1.
- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size();
        vector<int> sorted_queries = queries;
        sort(sorted_queries.begin(), sorted_queries.end());
        sort(intervals.begin(), intervals.end());

        // pq: {size of interval, end of interval}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // mp: {query, size of interval}
        unordered_map<int, int> mp;

        // We are traversing 'intervals' only once
        int i=0, left, right;
        for(int j=0; j<sorted_queries.size(); j++){
            int q=sorted_queries[j];

            // Adding all the intervals with 'start' >= 'q' in the 'pq'
            //   sorted based on the size of the interval
            while(i<n && q>=intervals[i][0]){
                left=intervals[i][0];
                right=intervals[i][1];
                pq.push({right-left+1, right});
                i++;
            }

            // Remove all the intervals from 'pq' that don't contain 'q'
            //   This works because the 'queries' are sorted and if the interval doesn't contain 'q'
            //   then it won't contain q+1,q+2,....
            while(!pq.empty() && pq.top().second<q) pq.pop();

            if(!pq.empty()) mp[q]=pq.top().first;
            else mp[q]=-1;
        }

        vector<int> ans;
        for(auto x: queries){
            ans.push_back(mp[x]);
        }

        return ans;
    }
};