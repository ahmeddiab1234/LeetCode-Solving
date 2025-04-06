// https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;


class Solution {
    public:
        long long pike_k(vector<int>& piles, int k){
            long long sum = 0;
            for(int p : piles){
                sum += (p + k - 1) / k;
            }
            return sum;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            int k=0;
            int left=1, right=*max_element(piles.begin(), piles.end());
            while(left<=right){
                int mid=left + (right-left)/2;
                if(pike_k(piles, mid)> h){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                    k=mid;
                }
            }
            return k;
        }
    };


int main()
{
    vector<int> piles = {3,6,7,11};
    cout << Solution().minEatingSpeed(piles, 8) << endl;
    piles = {30,11,23,4,20};
    cout << Solution().minEatingSpeed(piles, 5) << endl;
    cout << Solution().minEatingSpeed(piles, 6) << endl;

    return 0;
}
