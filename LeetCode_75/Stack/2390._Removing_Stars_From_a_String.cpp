// https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75


#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution 
{
    public:
        string removeStars(string s) 
        {
            string res="";
            stack<char> stk;
            for(char ch : s)
            {
                if(ch!='*') stk.push(ch);
                else stk.pop();
            }
            while (!stk.empty())
            {
                res+=stk.top();
                stk.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }
};
    

int main()
{
    string str = "leet**cod*e";
    cout << Solution().removeStars(str) << endl;

    str = "erase*****";
    cout << Solution().removeStars(str) << endl;

    return 0;
}


/*
Input: s = "leet**cod*e"
Output: "lecoe"

Input: s = "erase*****"
Output: "" 
*/