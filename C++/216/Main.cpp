Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. 
The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60

class Solution {
public:
    void rec(vector<vector<int>>& res, vector<int> subres,int& sum,const int& k, const int&n, int i){
        if(subres.size()==k && sum==n){
            res.push_back(subres);
            return;
         }
         if(i>9)return;
         if(sum > n)return;
         else if(subres.size()==k)return;
         subres.push_back(i);
         sum+=i;
         rec(res,subres,sum,k,n,i+1);
         subres.pop_back();
         sum-=i;
         rec(res,subres,sum,k,n,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subres;
        vector<vector<int>> res;
        int sum=0;
        rec(res,subres,sum,k,n,1);
        return res;
    }
};

class Solution {
public:
    void solve(int ind,int k,int n,vector<vector<int>>&ans,vector<int>&ds,int sum){
    if(ds.size()==k){
        if(sum==n){
            ans.push_back(ds);
        }
        return;
    }
    for(int i=ind+1;i<=9;i++){
        if(sum+i<=n && ds.size()<=k){
            ds.push_back(i);
            solve(i, k, n, ans, ds, sum+i);
            ds.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>>ans;
    vector<int>ds;
    solve(0,k,n,ans,ds,0);
    return ans;
    }
};