// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int maxVowels(string s, int k) 
    {
        int n = s.size();
        int cnt = 0, max_cnt = 0;
        auto is_vowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        for(int i = 0; i < n; i++)
        {
            if(is_vowel(s[i])) cnt++;
            if(i >= k && is_vowel(s[i - k])) cnt--;
            if(i >= k - 1) max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};
  

int main()
{
    string s = "abciiidef";
    cout << Solution().maxVowels(s, 3) << endl;

    s = "aeiou";
    cout << Solution().maxVowels(s, 2) << endl;

    s = "leetcode";
    cout << Solution().maxVowels(s, 3) << endl;

    return 0;
}
