// https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9+7;

class Solution {
    public:
        int numTilings(int n) {
            if (n == 1) return 1;
            if (n == 2) return 2;
            
            vector<long long> dp(n+1, 0);
            vector<long long> partial(n+1, 0);
            
            dp[0] = 1;
            dp[1] = 1;
            dp[2] = 2;
            partial[1] = 1;
            partial[2] = 2;
            
            for (int i = 3; i <= n; i++) {
                dp[i] = (dp[i-1] + dp[i-2] + 2 * partial[i-2]) % MOD;
                partial[i] = (partial[i-1] + dp[i-1]) % MOD;
            }
            
            return dp[n];
        }
};
    

int main(){
    cout << Solution().numTilings(3) << endl; // 5
    cout << Solution().numTilings(1) << endl; // 1

    return 0;
}