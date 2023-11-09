#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int C_upper = m+n-1;
        int C_lower = m < n ? m - 1:n - 1 ;
        vector<long long int> cache(C_lower + 1,1);
        for (int i = 1; i <= C_lower;i++){
            cache[i] = cache[i-1] * (C_upper -i) / i ;
        }
        return cache.back();
    }
};

int main(){
    Solution sol;
    cout << sol.uniquePaths(3,7) << endl;
}