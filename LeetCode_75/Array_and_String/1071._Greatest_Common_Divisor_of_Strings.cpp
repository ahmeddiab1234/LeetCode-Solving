// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
using namespace std;

int gcd(int sz1, int sz2)
{
    if(sz2==0)
        return sz1;
    return gcd(sz2, sz1%sz2);
}

class Solution 
{
    public:
        string gcdOfStrings(string str1, string str2) 
        {
            if (str1 + str2 != str2 + str1)  
                return "";

            int str_gcd = gcd(str1.size(), str2.size());
            return str1.substr(0, str_gcd);
        }
};

int main()
{
    string str1 = "ABCABC", str2 = "ABC";
    cout << Solution().gcdOfStrings(str1, str2) << endl;

    str1 = "ABABAB", str2 = "ABAB";
    cout << Solution().gcdOfStrings(str1, str2) << endl;

    str1 = "LEET", str2 = "CODE";
    cout << Solution().gcdOfStrings(str1, str2) << endl;



    return 0;
}

