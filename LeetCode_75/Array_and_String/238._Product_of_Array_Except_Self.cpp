// https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;
using ll = long long;


class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        int zeroCount = 0, product = 1;
        for (int num : nums) 
        {
            if (num == 0) zeroCount++;
            else product *= num;
        }

        for (int i = 0; i < n; i++) 
        {
            if (zeroCount > 1) ans[i] = 0;
            else if (zeroCount == 1) ans[i] = (nums[i] == 0) ? product : 0;
            else ans[i] = product / nums[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> answer = Solution().productExceptSelf(nums);
    for(auto i: answer)
    {
        cout << i << ' ';
    }
    cout << endl;

    nums = {-1,1,0,-3,3};
    answer = Solution().productExceptSelf(nums);
    for(auto i: answer)
    {
        cout << i << ' ';
    }


    return 0;
}

