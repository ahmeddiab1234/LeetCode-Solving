// https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int left = 0, right = 0, res = 0, zeros = 0;
        
        while (right < nums.size())
        {
            if (nums[right] == 0) zeros++;
            while (zeros > k)
            {
                if (nums[left] == 0) zeros--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        
        return res;
    }
};


int main()
{
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    cout << Solution().longestOnes(arr, 2) << endl;

    arr = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << Solution().longestOnes(arr, 3) << endl;

    return 0;
}

/*
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
*/