// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> res;
        set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());

        vector<int> branch1, branch2;
        for(int i : st1)
        {
            if(st2.find(i) == st2.end())
                branch1.push_back(i);
        }
        for(int i : st2)
        {
            if(st1.find(i) == st1.end())
                branch2.push_back(i);
        }
        res.push_back(branch1);
        res.push_back(branch2);
        return res;
    }
};

int main()
{
    vector<int> arr1 = {1, 2, 3}, arr2 = {2, 4, 6};
    vector<vector<int>> res = Solution().findDifference(arr1, arr2);
    for(auto i : res)
    {
        for(auto j: i)
            cout << j << ' ';
        cout << endl;
    }

    return 0;
}

