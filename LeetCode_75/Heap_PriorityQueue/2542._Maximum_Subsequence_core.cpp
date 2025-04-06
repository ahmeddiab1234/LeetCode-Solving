// https://leetcode.com/problems/maximum-subsequence-score/description/?envType=study-plan-v2&envId=leetcode-75

#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;


class Solution 
{
    public:
    
    ll maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int, int>> arr;
        for(int i = 0; i < nums1.size(); i++)
            arr.push_back({nums2[i], nums1[i]});

        sort(arr.rbegin(), arr.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0, res = 0;

        for(auto &[n2, n1] : arr)
        {
            pq.push(n1);
            sum += n1;
            if(pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
            {
                res = max(res, sum * (ll)n2);
            }
        }
        return res;
    }

};


int main()
{
    vector<int> arr1 = {1, 3, 3, 2};
    vector<int> arr2 = {2, 1, 3, 4};
    cout << Solution().maxScore(arr1, arr2, 3) << endl;

    return 0;
}
