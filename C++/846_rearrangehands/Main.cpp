Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, 
and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
return true if she can rearrange the cards, or false otherwise.

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize!=0) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> map;
        for(int i:hand)map[i]++;
        for(int i:hand){
            if(map[i] > 0){
                map[i]--;
                for(int k=1;k<groupSize;k++){
                    if(map.find(i+k) == map.end() || map[i+k] == 0)return false;
                    map[i+k]--;
                }
            }
        }
        return true;
    }
};