// https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=leetcode-75

#include<vector>
#include<iostream>
#include<cassert>
#include<queue>
using namespace std;


class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pri;
        for(int n : nums)
        {
            pri.push(n);
        }

        int val = -1;
        int idx=1;

        while(!pri.empty())
        {
            int n= pri.top();
            if(idx==k)
            {
                val=n;  break;
            }
            idx++;
            pri.pop();
        }
        return val;
    }
};


int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(arr, 2) << endl;

    arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << Solution().findKthLargest(arr, 4) << endl;

    return 0;
}
