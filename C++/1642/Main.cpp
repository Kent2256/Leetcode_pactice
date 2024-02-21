class Solution {
public:
    int rec(vector<int>& heights, int cur, int bricks, int ladders){
        if(cur == heights.size()-1)return cur;
        int cur_h = heights[cur], next_h = heights[cur+1];
        if(cur_h >= next_h)return rec(heights,cur+1,bricks,ladders);
        else{
            if(bricks >= (next_h-cur_h) && ladders > 0){
                return max(rec(heights,cur+1,bricks-(next_h-cur_h),ladders),rec(heights,cur+1,bricks,ladders-1));
            }
            else if(bricks >= (next_h-cur_h)){
                return rec(heights,cur+1,bricks-(next_h-cur_h),ladders);
            }
            else if(ladders > 0){
                return rec(heights,cur+1,bricks,ladders-1);
            }
        }
        return cur;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return rec(heights,0,bricks,ladders);
    }
};


class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> h_diff;
        for(int i=1;i<heights.size();i++){
            if(heights[i] > heights[i-1])h_diff.push_back(heights[i]-heights[i-1]);
            else h_diff.push_back(0);
        }
        priority_queue<int> pq;
        int cur = 0;
        while(cur < h_diff.size()){
            if(h_diff[cur]==0){
                cur++;
                continue;
            }
            else{
                pq.push(h_diff[cur]);
                bricks-=h_diff[cur];
                if(bricks< 0 && ladders > 0){
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                }
                else if(bricks< 0){
                    return cur;
                }
                cur++;
            }
        }
        return cur;
    }
};