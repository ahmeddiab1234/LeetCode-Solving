// https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        bool increasingTriplet(vector<int>& nums) 
        {
            int first = INT_MAX, second = INT_MAX;
            for (int num : nums) 
            {
                if (num <= first) first = num;
                else if (num <= second) second = num;
                else return true;
            }
            return false;
        }
};

int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout << Solution().increasingTriplet(nums) << endl; // true

    nums = {5,4,3,2,1};
    cout << Solution().increasingTriplet(nums) << endl; // false

    nums = {2,1,5,0,4,6};
    cout << Solution().increasingTriplet(nums) << endl; // true

    return 0;
}
