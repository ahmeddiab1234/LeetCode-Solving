// https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size() ==1) return 0;

        int n= nums.size();
        
        int left=0, right=nums.size()-1, peak=0;
        while(left <= right ){
            int mid = left + (right-left)/2;
            if(mid+1==nums.size()) {
                peak = mid; break;
            }
            if(nums[mid] < nums[mid+1]){
                left = mid+1;
            }
            else
            {
                right=mid-1;
                peak=mid;
            }
        }   
        return peak;
    }
};


int main()
{
    vector<int> nums = {1,2,3,1};
    cout << Solution().findPeakElement(nums) << endl;
    nums = {1,2,1,3,5,6,4};
    cout << Solution().findPeakElement(nums) << endl;

    return 0;
}
