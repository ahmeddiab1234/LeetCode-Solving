// https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution 
{
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n = gain.size();
        vector<int> pref(n+1, 0);
        for(int i=1; i<n+1; i++)
        {
            pref[i] = pref[i-1] + gain[i-1];
        }
        int max_pref = *max_element(pref.begin(), pref.end());
        return max_pref;
    }
};

int main()
{
    vector<int> gain = {-5,1,5,0,-7};
    cout << Solution().largestAltitude(gain) << endl;

    gain = {-4,-3,-2,-1,4,3,2};
    cout << Solution().largestAltitude(gain) << endl;

    return 0;
}
