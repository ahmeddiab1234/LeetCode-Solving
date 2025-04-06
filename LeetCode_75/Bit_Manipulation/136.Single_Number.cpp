// https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int n: nums){
            res ^=n;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {2,2,1};
    cout << Solution().singleNumber(nums) << endl;
    nums = {4,1,2,1,2};
    cout << Solution().singleNumber(nums) << endl;
    nums = {1};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}
