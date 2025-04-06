// https://leetcode.com/problems/reverse-vowels-of-a-string/?envType=study-plan-v2&envId=leetcode-75
#include<iostream>
#include<algorithm>
using namespace std;


class Solution 
{
    public:
        string reverseVowels(string s) 
        {
            string vols="", res="";
            for(int i=0; i<s.size(); i++)
            {
                if(tolower(s[i]) == 'a' ||
                tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'i' ||
                tolower(s[i]) == 'o' ||
                tolower(s[i]) == 'u' )
                {
                    vols += s[i];
                }
            }

            reverse(vols.begin(), vols.end());
            int cnt=0;

            for(int i=0; i<s.size(); i++)
            {
                if(tolower(s[i]) == 'a' ||
                tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'i' ||
                tolower(s[i]) == 'o' ||
                tolower(s[i]) == 'u')
                {
                    res += vols[cnt];
                    cnt++;
                }
                else    
                    res += s[i];
            }
            return res;
        }
};



int main()
{
    string s = "IceCreAm";
    cout << Solution().reverseVowels(s) << endl;
    
    s = "leetcode";
    cout << Solution().reverseVowels(s) << endl;
    
    return 0;
}

/*
Input: s = "IceCreAm"

Output: "AceCreIm"

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Input: s = "leetcode"

Output: "leotcede"
*/