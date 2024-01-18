There is a 0-indexed array nums of length n. Initially, all elements are uncolored (has a value of 0).

You are given a 2D integer array queries where queries[i] = [indexi, colori].

For each query, you color the index indexi with the color colori in the array nums.

Return an array answer of the same length as queries where 
answer[i] is the number of adjacent elements with the same color after the ith query.

More formally, answer[i] is the number of indices j, 
such that 0 <= j < n - 1 and nums[j] == nums[j + 1] and nums[j] != 0 after the ith query.

 

Example 1:

Input: n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]
Output: [0,1,1,0,2]
Explanation: Initially array nums = [0,0,0,0], where 0 denotes uncolored elements of the array.
- After the 1st query nums = [2,0,0,0]. The count of adjacent elements with the same color is 0.
- After the 2nd query nums = [2,2,0,0]. The count of adjacent elements with the same color is 1.
- After the 3rd query nums = [2,2,0,1]. The count of adjacent elements with the same color is 1.
- After the 4th query nums = [2,1,0,1]. The count of adjacent elements with the same color is 0.
- After the 5th query nums = [2,1,1,1]. The count of adjacent elements with the same color is 2.
Example 2:

Input: n = 1, queries = [[0,100000]]
Output: [0]
Explanation: Initially array nums = [0], where 0 denotes uncolored elements of the array.
- After the 1st query nums = [100000]. The count of adjacent elements with the same color is 0.
 

Constraints:

1 <= n <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= indexi <= n - 1
1 <=  colori <= 105
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        if(n==1)return {0};
        unordered_map<int,int> map;
        vector<int> result;
        map[queries[0][0]]= queries[0][1];
        result.push_back(0);
        for(int i=1;i< queries.size();i++){
            int subres=result.back();
            int cur_index=queries[i][0],cur_color=queries[i][1],old_color;
            if(map.find(cur_index)!=map.end())old_color = map[cur_index];
            else old_color=0;
            map[cur_index]=cur_color;
            if(cur_color==old_color){
                result.push_back(subres);
                continue;
            }
            if(map.find(cur_index-1)!=map.end()){
                if(map[cur_index-1] == old_color)subres--;
                else if(map[cur_index-1] == cur_color)subres++;
            }
            if(map.find(cur_index+1)!=map.end()){
                if(map[cur_index+1] == old_color)subres--;
                else if(map[cur_index+1] == cur_color)subres++;
            }
            result.push_back(subres);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        if(n==1)return vector<int>(queries.size(),0);
        vector<int> color(n,0);
        vector<int> result;
        color[queries[0][0]]= queries[0][1];
        result.push_back(0);
        for(int i=1;i< queries.size();i++){
            int subres=result.back();
            int cur_index=queries[i][0],cur_color=queries[i][1];
            int old_color = color[cur_index];
            color[cur_index]=cur_color;
            if(cur_color==old_color){
                result.push_back(subres);
                continue;
            }
            if(cur_index-1 >=0 && color[cur_index-1]!=0){
                if(color[cur_index-1] == old_color)subres--;
                else if(color[cur_index-1] == cur_color)subres++;
            }
            if(cur_index+1 < n && color[cur_index+1]!=0){
                if(color[cur_index+1] == old_color)subres--;
                else if(color[cur_index+1] == cur_color)subres++;
            }
            result.push_back(subres);
        }
        return result;
    }
};