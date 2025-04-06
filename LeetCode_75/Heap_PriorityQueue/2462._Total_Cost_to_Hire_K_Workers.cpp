// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;

class Solution 
{
public:
    ll totalCost(vector<int>& costs, int k, int candidates) 
    {
        ll min_cost_sum = 0;
        int n = costs.size();
        int left_ptr = 0, right_ptr = n - 1;

        priority_queue<int, vector<int>, greater<int>> left_heap, right_heap;

        for (int i = 0; i < candidates && left_ptr <= right_ptr; i++, left_ptr++)
            left_heap.push(costs[left_ptr]);

        for (int i = 0; i < candidates && left_ptr <= right_ptr; i++, right_ptr--)
            right_heap.push(costs[right_ptr]);

        while (k--) 
        {
            if (!left_heap.empty() && (right_heap.empty() || left_heap.top() <= right_heap.top())) 
            {
                min_cost_sum += left_heap.top();
                left_heap.pop();
                if (left_ptr <= right_ptr) 
                {
                    left_heap.push(costs[left_ptr]);
                    left_ptr++;
                }
            } 
            else 
            {
                min_cost_sum += right_heap.top();
                right_heap.pop();
                if (left_ptr <= right_ptr) 
                {
                    right_heap.push(costs[right_ptr]);
                    right_ptr--;
                }
            }
        }

        return min_cost_sum;
    }
};

