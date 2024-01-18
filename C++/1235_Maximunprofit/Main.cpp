We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays,
 return the maximum profit you can take such that there are no two jobs in the 
 subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:

1 2 3
2 3 4
3 4 5
3 4 5 6

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104'

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = make_tuple(endTime[i], startTime[i], profit[i]);
        }
        sort(v.begin(), v.end());
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = get<2>(v[i]);
            if (i > 0) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            {
                int l = 0, r = i - 1, at = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (get<0>(v[mid]) <= get<1>(v[i])) {
                        l = mid + 1;
                        at = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (at != -1) {
                    dp[i] = max(dp[i], dp[at] + get<2>(v[i]));
                }
            }
        }
        return dp[n - 1];
    }
};