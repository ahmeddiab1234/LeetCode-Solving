// https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int n=nums.size();
        double avg = 0.0, sum=0.0;
        for(int i=0; i<k; i++)  sum += nums[i];
        avg = sum/k;
        for(int i=k; i<n; i++)
        {
            sum+= nums[i] - nums[i-k];
            avg = max(avg, sum/k); 
        }
        return avg;
    }
};


int main()
{
    vector<int> nums = {1,12,-5,-6,50,3};
    cout << Solution().findMaxAverage(nums, 4) << endl;

    nums = {5};
    cout << Solution().findMaxAverage(nums, 1) << endl;

    return 0;
}

