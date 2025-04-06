// https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int cnt=0, left=0, right=n-1, sum=0;
        while (left < right)
        {
            sum  = nums[left] + nums[right];
            if(sum == k)
            {
                left++, right--, cnt++;
            }
            else if(sum > k)
            {
                right--;
            }
            else
                left++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    cout << Solution().maxOperations(nums, 5) << endl;

    nums = {3,1,3,4,3};
    cout << Solution().maxOperations(nums, 6) << endl;

    return 0;
}
