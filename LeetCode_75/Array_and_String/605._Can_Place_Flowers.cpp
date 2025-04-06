// https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count = 0;
        int size = flowerbed.size();
        
        for(int i = 0; i < size; i++)
        {
            if(flowerbed[i] == 0)
            {
                bool left_empty = (i == 0 || flowerbed[i-1] == 0);
                bool right_empty = (i == size-1 || flowerbed[i+1] == 0);
                
                if(left_empty && right_empty)
                {
                    flowerbed[i] = 1; 
                    count++; 
                    if(count >= n) return true;
                }
            }
        }
        return count >= n;
    }
};


int main()
{
    vector<int> flowrs = {1,0,0,0,1};
    int n=1;
    cout << Solution().canPlaceFlowers(flowrs, n) << endl;

    flowrs = {1,0,0,0,1};
    n=2;
    cout << Solution().canPlaceFlowers(flowrs, n) << endl;

    return 0;
}

/*
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/