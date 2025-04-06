// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), [](auto &a, auto &b) { return a[1] < b[1]; });

        int cnt=0;
        long long end_p = LONG_LONG_MIN;
        for(auto &poi: points)
        {
            if(poi[0] > end_p)
            {
                cnt++;
                end_p = poi[1];
            }
        }

        return cnt;
    }
};

int main()
{
    vector<vector<int>> arr = { {10,16}, {2,8}, {1,6}, {7,12} };
    cout << Solution().findMinArrowShots(arr) << endl;
    
    arr = { {1,2}, {3,4}, {5,6}, {7,8} };
    cout << Solution().findMinArrowShots(arr) << endl;
    
    arr = { {1,2}, {2,3}, {3,4}, {4,5} };
    cout << Solution().findMinArrowShots(arr) << endl;

    return 0;
}
