#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int eattime(vector<int>& piles, int k){
        int ans=0;
        for (int pile:piles){
            ans += pile%k ? pile/k+1:pile/k;
        }
        return ans;
    }
    int minEatingSpeed2(vector<int>& piles, int h) {
        int res=0;
        long long int sum=0;
        int p_len = piles.size();
        if( p_len == h){
            for(int pile:piles)res=max(res,pile);
            return res;
        }
        for(int pile:piles)sum+=pile;
        long long int l = sum/h;
        long long int r = sum/(h-p_len)+1;
        long long int mid;
        while(l < r){
            mid = (l+r)/2;
            if(eattime(piles,mid) <= h)r=mid;
            else l=mid+1;
        }
        return r;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_p=0;
        int l=1;
        int p_len = piles.size();
        for(int pile:piles)max_p=max(max_p,pile);
        if( p_len == h)return max_p;
        long long int r = max_p;
        long long int mid;
        while(l < r){
            mid = (l+r)/2;
            if(eattime(piles,mid) <= h)r=mid;
            else l=mid+1;
        }
        return r;
    }
};

int main(){
    vector<int> piles = {1000000000,1000000000};
    int h = 3;
    Solution sol;
    cout << sol.minEatingSpeed(piles,h);
}
    //8 = 11/k+7/k+6/k+3/k;
    //8 = 27/k + 4
    //min = 27/8 =3
    //max = 27/4 = 7 
    // 3 5 6 4==>8
    // 3 4 5 5==>8
    // 3 3 4 3==>10
    // 4 4
    //[30,11,23,4,20], h = 5
    // sum = 88
    // min = 88/5 = 17
    // h -size() == 1 k = max(int);
    // [30,11,23,4,20], h = 6
    //min = 17
    //max = 88
    
