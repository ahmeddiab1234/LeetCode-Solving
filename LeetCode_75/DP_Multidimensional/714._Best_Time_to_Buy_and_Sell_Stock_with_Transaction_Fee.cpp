// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 5e4 + 1;
int memory[MAX][2];
vector<int> prices_;
int fee_;

class Solution {
public:
    int dp(int day, int holding) {
        if (day == prices_.size()) return 0;
        int &ret = memory[day][holding];
        if (ret != -1) return ret;

        if (holding) {
            ret = max(
                dp(day + 1, 0) + prices_[day] - fee_,
                dp(day + 1, 1)
            );
        } else {
            ret = max(
                dp(day + 1, 1) - prices_[day],
                dp(day + 1, 0)
            );
        }

        return ret;
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(memory, -1, sizeof(memory));
        prices_ = prices;
        fee_ = fee;
        return dp(0, 0);
    }
};


int main(){
    vector<int> arr = {1,3,2,8,4,9};
    cout << Solution().maxProfit(arr, 2) << endl;
    
    arr = {1,3,7,5,10,3};
    cout << Solution().maxProfit(arr, 3) << endl;

    return 0;
}

