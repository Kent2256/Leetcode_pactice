class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)return left;
        if((left^right) > left) return 0;
        int temp = (left&right)^right;
        int pos=0;
        while(temp!=0){
            pos << 1;
            pos ++;
            temp = temp >> 1;
        }
        int mask = INT_MAX^pos;
        return left&mask;
    }
};

