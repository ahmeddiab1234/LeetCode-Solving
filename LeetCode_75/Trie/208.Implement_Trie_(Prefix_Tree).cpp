// https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<cstring>	
#include<vector>	
#include<string>	
using namespace std;

class Trie 
{
    private:
        static const int MAX_CHAR = 26;
        Trie* child[MAX_CHAR];
        bool isLeaf { };

    public:
        Trie() 
        {
            memset(child, 0, sizeof(child));
        }
        
        void insert(string str, int idx = 0) {
            if (idx == (int) str.size())
                isLeaf = 1;
            else {
                int cur = str[idx] - 'a';
                if (child[cur] == 0)
                    child[cur] = new Trie();
                child[cur]->insert(str, idx + 1);
            }
        }
        
        bool search(string str, int idx=0) 
        {
            if (idx == (int) str.size())
			return isLeaf;	

            int cur = str[idx] - 'a';
            if (!child[cur])
                return false;	

            return child[cur]->search(str, idx + 1);
        }
        
        bool startsWith(string str, int idx=0) 
        {
            if (idx == (int) str.size())
			return true;	

            int cur = str[idx] - 'a';
            if (!child[cur])
                return false;	

		    return child[cur]->startsWith(str, idx + 1);
        }
};