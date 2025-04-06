// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
        {
            int n=candies.size();
            int max_num = *max_element(candies.begin(), candies.end());
            
            vector<bool> result(n, false);

            for(int i=0; i<n; i++)
            {
                if(candies[i]+extraCandies >= max_num)  result[i] = true;
            }
            return result;
        }
};


int main()
{
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    vector<bool> res = Solution().kidsWithCandies(candies, extraCandies);
    for(auto b : res)
    {
        cout << b << ' ';
    }
    cout << endl;
    
    candies = {4,2,1,1,2};
    extraCandies = 1;
    res = Solution().kidsWithCandies(candies, extraCandies) ;
    for(auto b : res)
    {
        cout << b << ' ';
    }
    cout << endl;

    candies = {12,1,12};
    extraCandies = 10;
    res = Solution().kidsWithCandies(candies, extraCandies);
    for(auto b : res)
    {
        cout << b << ' ';
    }


    return 0;
}
/*
Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
*/