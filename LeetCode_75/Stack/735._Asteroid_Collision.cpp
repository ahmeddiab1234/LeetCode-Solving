// https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> stack;
        for (int ast : asteroids) 
        {
            bool destroyed = false;
            while (!stack.empty() && ast < 0 && stack.back() > 0) 
            {
                if (stack.back() < -ast) 
                {
                    stack.pop_back();
                    continue;
                } 
                else if (stack.back() == -ast) 
                {
                    stack.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) 
            {
                stack.push_back(ast);
            }
        }
        return stack;
    }
};

int main()
{
    vector<int> nums = {5, 10, -5};
    vector<int> res = Solution().asteroidCollision(nums);
    for(auto n: res)    
    {
        cout << n << ' ';
    }
    cout << endl;

    nums = {8, -8};
    res = Solution().asteroidCollision(nums);
    for(auto n: res)    
    {
        cout << n << ' ';
    }
    cout << endl;

    nums = {10, 2, -5};
    res = Solution().asteroidCollision(nums);
    for(auto n: res)    
    {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
