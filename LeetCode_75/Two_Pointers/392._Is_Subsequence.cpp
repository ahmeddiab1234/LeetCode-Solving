// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int s_idx=0, t_idx=0, cnt=0;
        while(s_idx < s.size() && t_idx < t.size())
        {
            if(s[s_idx] == t[t_idx])
            {
                cnt ++;
                s_idx++;
            }
            t_idx++;
        }

        return cnt==s.size();
    }
};

int main()
{
    string s1 = "abc", t1 = "ahbgdc";
    cout << Solution().isSubsequence(s1, t1) << endl;

    s1 = "axc", t1 = "ahbgdc";
    cout << Solution().isSubsequence(s1, t1) << endl;

    return 0;
}
/*
Input: s = "abc", t = "ahbgdc"
Output: true
Input: s = "axc", t = "ahbgdc"
Output: false
*/