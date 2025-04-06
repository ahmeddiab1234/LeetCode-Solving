// https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] != 0) 
            {
                nums[pos++] = nums[i];
            }
        }
        while (pos < nums.size()) 
        {
            nums[pos++] = 0;
        }
    }
};

int main()
{
    vector<int> arr = {0,1,0,3,12};
    Solution().moveZeroes(arr);
    for(auto a : arr) cout << a << ' ';
    cout << endl;
    
    vector<int> arr2 = {0};
    Solution().moveZeroes(arr2);
    for(auto a : arr2) cout << a << ' ';

    return 0;
}