// https://leetcode.com/problems/search-suggestions-system/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Trie 
{
    Trie* child[26];
    vector<string> suggestions;

public:
    Trie() 
    {
        for(int i=0; i<26; i++) child[i] = nullptr;
    }

    void insert(const string& word) 
    {
        Trie* node = this;
        for(char c : word) 
        {
            int idx = c - 'a';
            if(!node->child[idx])
                node->child[idx] = new Trie();
            node = node->child[idx];
            if(node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
    }

    vector<string> getSuggestions(const string& prefix) 
    {
        Trie* node = this;
        for(char c : prefix)
        {
            int idx = c - 'a';
            if(!node->child[idx])
                return {};
            node = node->child[idx];
        }
        return node->suggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(), products.end());
        Trie root;
        for(const string& product : products) 
            root.insert(product);

        vector<vector<string>> result;
        string prefix;
        for(char c : searchWord) 
        {
            prefix += c;
            result.push_back(root.getSuggestions(prefix));
        }
        return result;
    }
};

