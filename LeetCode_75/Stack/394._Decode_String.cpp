// https://leetcode.com/problems/decode-string/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution 
{
    public:
        string decodeString(string s) 
        {
            stack<int> countStack;
            stack<string> stringStack;
            string curr;
            int num = 0;
    
            for (char ch : s) 
            {
                if (isdigit(ch)) {
                    num = num * 10 + (ch - '0');
                } 
                else if (ch == '[') 
                {
                    countStack.push(num);
                    stringStack.push(curr);
                    num = 0;
                    curr = "";
                } 
                else if (ch == ']') 
                {
                    int cnt = countStack.top(); countStack.pop();
                    string temp = stringStack.top(); stringStack.pop();
                    while (cnt--) temp += curr;
                    curr = temp;
                }
                 else 
                {
                    curr += ch;
                }
            }
            return curr;
        }
};
    

int main()
{
    string str = "3[a]2[bc]";
    cout << Solution().decodeString(str) << endl;

    str = "3[a2[c]]";
    cout << Solution().decodeString(str) << endl;

    str = "2[abc]3[cd]ef";
    cout << Solution().decodeString(str) << endl;

    return 0;
}

/*
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/