// https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> vals;
int sum=0;
const int MAX = 1000 + 1;
int Memory[MAX];

int dp_cost(int idx)
{
    if(idx>=vals.size())
        return sum;
    int& ret = Memory[idx];
    if(ret != -1)
        return ret;

    return ret = vals[idx] +min(dp_cost(idx+1), dp_cost(idx+2));
}

class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vals = cost;
        memset(Memory, -1, sizeof(Memory));
        return min(dp_cost(0), dp_cost(1));
    }
};

