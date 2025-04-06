// https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75
 
#include<iostream>
using namespace std;

class Solution 
{
public:
    string mergeAlternately(string word1, string word2) 
    {
        string res="", add="";
        int sz = min(word1.size(), word2.size());

        if(word1.size() != word2.size()) 
        {
            if(word1.size() > word2.size()) add = word1.substr(sz);
            else    add = word2.substr(sz);
        }
        for(int i=0; i<sz; i++)
        {
            res += word1[i];
            res += word2[i];
        }
        res += add;
        return res;
    }
};


int main()
{
    string word1 = "abc", word2 = "pqr";
    cout << Solution().mergeAlternately(word1, word2)<<endl;

    word1 = "ab", word2 = "pqrs";
    cout << Solution().mergeAlternately(word1, word2)<<endl;

    word1 = "abcd", word2 = "pq";
    cout << Solution().mergeAlternately(word1, word2)<<endl;

    return 0;
}
