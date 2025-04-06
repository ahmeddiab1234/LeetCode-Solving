// https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size() - 1, max_area = 0;

        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return max_area;
    }
};


int main()
{
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(h) << endl;

    h = {1,1};
    cout << Solution().maxArea(h) << endl;

    return 0;
}

