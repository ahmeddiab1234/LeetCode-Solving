// https://leetcode.com/problems/non-overlapping-intervals/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        int cnt = 0;
        int prev_end = INT_MIN;
        for (auto &intv : intervals) 
        {
            if (intv[0] >= prev_end) 
            {
                prev_end = intv[1];
            } 
            else 
            {
                cnt++;
            }
        }
        return cnt;
    }
};



int main()
{
    vector<vector<int>> arr { {1,2}, {2,3}, {3,4}, {1,3} };
    cout << Solution().eraseOverlapIntervals(arr) << endl;
    
    arr = { {1,2}, {1,2}, {1,3} };
    cout << Solution().eraseOverlapIntervals(arr) << endl;

    arr = { {1,2}, {2,3}};
    cout << Solution().eraseOverlapIntervals(arr) << endl;
    
    arr = { {1,100}, {11,22}, {1,11}, {2,12} };
    cout << Solution().eraseOverlapIntervals(arr) << endl;

    return 0;
}
