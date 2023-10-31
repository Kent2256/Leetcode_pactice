// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n==1)return n;
        long long int l=1,r=n;
        long int mid;
        while(l<=r){
            long int mid = (l+r)/2;
            bool res = isBadVersion(mid);
            if(!res) l = mid + 1;
            else{
                    r = mid -1 ;
                }
            }
        return mid;
    }
};