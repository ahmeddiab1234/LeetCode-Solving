// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int, int> mp;
        for (int a : arr) mp[a]++;

        set<int> occurrences;
        for (auto &p : mp)
        {
            if (!occurrences.insert(p.second).second) 
                return false;
        }
        return true;
    }
};


int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << Solution().uniqueOccurrences(arr) << endl;

    arr = {1, 2};
    cout << Solution().uniqueOccurrences(arr) << endl;
    
    arr = {-3,0,1,-3,1,1,1,-3,10,0};
    cout << Solution().uniqueOccurrences(arr) << endl;

    return 0;
}

