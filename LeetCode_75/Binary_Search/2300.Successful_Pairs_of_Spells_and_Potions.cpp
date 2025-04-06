// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for(int i=0; i<spells.size(); i++)
        {
            int cnt=0, left=0, right=potions.size()-1;
            while(left<=right){
                long long mid = left + (right-left)/2;
                if(spells[i]*potions[mid] >= success){
                    right=mid-1;
                }
                else{
                    left = mid+1;
                    cnt=potions.size()-left;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main()
{
    vector<int> spell = {5,1,3};
    vector<int> pothion = {1,2,3,4,5};
    vector<int> res = Solution().successfulPairs(spell, pothion, 7);
    for(int r: res) 
        cout << r << ' ';
    cout << endl;
    spell = {3,1,2};
    pothion = {8,5,8};
    res = Solution().successfulPairs(spell, pothion, 16);
    for(int r: res) 
        cout << r << ' ';
    cout << endl;

    return 0;
}
/*
Output: [4,0,3]
Output: [2,0,2]
*/