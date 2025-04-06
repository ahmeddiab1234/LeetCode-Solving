// hhttps://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        string reverseWords(string s) 
        {
            vector<string> strs;
            string hel="", res="";
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]!=' ')
                {
                    hel+=s[i];
                }
                if(hel.size()>0 && s[i]==' ')
                {
                    strs.push_back(hel);
                    hel = "";
                }
            }
            if(!hel.empty())    
                strs.push_back(hel);

            reverse(strs.begin(), strs.end());
            
            for(int i=0; i<strs.size(); i++)
            {
                res += strs[i];
                if(i!=strs.size()-1)    res+=' ';
            }
            return res;
        }
};


int main()
{
    string s = "the sky is blue";
    cout << Solution().reverseWords(s) << endl;
    
    s = "  hello world  ";
    cout << Solution().reverseWords(s) << endl;

    s = "a good   example";
    cout << Solution().reverseWords(s) << endl;

    return 0;
}

