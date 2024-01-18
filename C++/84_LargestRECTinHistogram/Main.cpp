Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, \
return the area of the largest rectangle in the histogram.'

 
Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int len = heights.size();
        int res = 0;
        stack<int> s;
        for(int i=0;i<len;i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                int height = heights[s.top()]; s.pop();
                int width = s.empty()? i : i-s.top()-1;
                res = max(height*width,res);
            }
            s.push(i);          
        }
        return res;
    }
};

ass Solution {
public:
    
    int largestRectangleArea(vector<int> & arr) {
        if (arr.empty()) return 0;
        if (arr.size() == 1) return arr[0];
        
        arr.push_back(-1);
        
        stack<int> s;
        int maxarea = 0;

// Monotomic Increasing Stack.
        for (int i = 0; i < arr.size(); i++) {
             while (!s.empty() && arr[s.top()] > arr[i]) {
                 int height = arr[s.top()]; s.pop();

// -- Since A[i] yet not processed, Hence i is the Width
// Empty Stack : suppose i is as 5 it ,mean 0 ... 4 has width of 5
                
                 int width = s.empty()? i : (i - 1 - s.top());
                 
                 maxarea = max(maxarea, height*width);
             }
            
             s.push(i);
        }
     
        return maxarea;
    }
};