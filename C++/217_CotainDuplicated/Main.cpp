class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for (int num:nums){
            map[num]++;
            if(map[num] > 1){
                return true;
            }
        }
        return false;
    }
     bool containsDuplicate(vector<int>& nums) {
        int res=0, prev=0;
        for (int num:nums){
            res^=num;
            if(res < prev){
                return true;
            }
            prev = res;
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> setz ;
        for (auto n: nums){
            if(setz.count(n)){
                return true;
            }
            else{
                setz.insert(n);
            }
        }
        return false;
    }
};