#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.empty())return image;
        if(image[sr][sc] == color)return image;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> queue;
        int target = image[sr][sc];
        queue.push_back({sr,sc});
        while(!queue.empty()){
            vector<int> dst = queue[queue.size()-1];
            queue.pop_back();
            image[dst[0]][dst[1]] = color;
            for(vector<int> d_dir:dir){
                int next_y = dst[0] + d_dir[0], next_x = dst[1] + d_dir[1];
                if((next_y >= 0) && (next_y < image.size()) && (next_x >=0 ) && (next_x < image[0].size())){
                    if(image[next_y][next_x] == target){
                        queue.push_back({next_y,next_x});
                    }
                }
            }
        }
        return image;
    }
};
/*
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int origColor = image[sr][sc];

        if (newColor == origColor) return image;

        stack<pair<int, int>> s;
        s.push({sr, sc});

        while (!s.empty()) {
            pair<int, int> curr = s.top();
            s.pop();
            int row = curr.first;
            int col = curr.second;

            if (row < 0 || col < 0 || row == m || col == n || image[row][col] != origColor) continue;

            image[row][col] = newColor;

            s.push({row - 1, col});
            s.push({row + 1, col});
            s.push({row, col - 1});
            s.push({row, col + 1});
        }

        return image;
    }
};
*/
int main(){
    vector<vector<int>> image ={{1,1,1},
                                {1,1,0},
                                {1,0,1}};
    int sr = 1, sc = 1, color = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image,1,1,2);
    for (auto t:result){
        for (auto s:t){
            cout << s << ",";
        }
        cout <<endl;
    }
}