// https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int MAX_idx = 100+1;
int memory[MAX_idx];
vector<int> values;

class Solution {
public:
    int dp(int idx){
        if(idx == values.size()-1){
            return values[idx];
        }
        if(idx >= values.size()){
            return 0;
        }
        int& ret = memory[idx];
        if(ret!=-1){
            return ret;
        }
        int leave = dp(idx+1);
        int pick = values[idx]+ dp(idx+2);
        return ret = max(leave, pick);
    }

    int rob(vector<int>& nums) {
        memset(memory, -1, sizeof(memory));
        values = nums;
        return dp(0);
    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    cout << Solution().rob(nums)<<endl;
    nums = {2,7,9,3,1};
    cout << Solution().rob(nums)<<endl;

    return 0;
}
