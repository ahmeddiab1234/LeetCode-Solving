// https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
       vector<vector<int>> mp1(grid.size()), mp2(grid.size());

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                mp1[i].push_back(grid[i][j]);
                mp2[i].push_back(grid[j][i]);
            }
        }
        int cnt=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(mp1[i] == mp2[j]) cnt++;
            }
        }
        return cnt;

    }
};

int main()
{
    vector<vector<int>> grid = {{3,2,1}, {1,7,6}, {2,7,7}};
    cout << Solution().equalPairs(grid) << endl;

    grid = {{3,1,2,2}, {1,4,4,5}, {2,4,2,2}, {2,4,2,2}};
    cout << Solution().equalPairs(grid) << endl;

    return 0;
}
