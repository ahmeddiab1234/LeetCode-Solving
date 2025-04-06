// https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.size() != word2.size()) return false;

        unordered_map<char, int> map1, map2;
        for(char c : word1) map1[c]++;
        for(char c : word2) map2[c]++;
        
        unordered_set<char> set1, set2;
        for(auto& p : map1) set1.insert(p.first);
        for(auto& p : map2) set2.insert(p.first);
        if(set1 != set2) return false;
        
        multiset<int> freq1, freq2;
        for(auto& p : map1) freq1.insert(p.second);
        for(auto& p : map2) freq2.insert(p.second);
        
        return freq1 == freq2;
    }
};


int main()
{
    string word1 = "abc", word2 = "bca";
    cout << Solution().closeStrings(word1, word2) << endl;

    word1 = "a", word2 = "aa";
    cout << Solution().closeStrings(word1, word2) << endl;
    
    word1 = "cabbba", word2 = "abbccc";
    cout << Solution().closeStrings(word1, word2) << endl;
    
    word1 = "abbzzca", word2 = "babzzcz";
    cout << Solution().closeStrings(word1, word2) << endl;

    return 0;
}
