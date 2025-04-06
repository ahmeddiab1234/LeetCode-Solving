// https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
   `
int main()
{
    vector<int> nums = {1,7,3,6,5,6};
    cout << Solution().pivotIndex(nums) << endl;
    
    nums = {1,2,3};
    cout << Solution().pivotIndex(nums) << endl;
    
    nums = {2,1,-1};
    cout << Solution().pivotIndex(nums) << endl;

    return 0;
}
