// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n=nums.size(), left=0, right=0, cnt_zeor=0;
        int max_1s=0;
        while(right < nums.size())
        {
            if(nums[right]==0)
                cnt_zeor++;

            while(cnt_zeor > 1)
            {
                if(nums[left]==0)
                    cnt_zeor--;
                left++;
            }

            max_1s = max(max_1s, right-left+1);
            right++;
        }

        return (cnt_zeor==0 ? n-1 : max_1s-1);
    }
};


int main()
{
    vector<int> nums = {1,1,0,1};
    cout << Solution().longestSubarray(nums) << endl;

    nums = {0,1,1,1,0,1,1,0,1};
    cout  << Solution().longestSubarray(nums) << endl;

    nums = {1,1,1};
    cout << Solution().longestSubarray(nums) << endl;

    return 0;
}
/*
Input: nums = [1,1,0,1]
Output: 3
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Input: nums = [1,1,1]
Output: 2
*/