// https://leetcode.com/problems/edit-distance/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;


string str1, str2;

const int MAX = 1000 + 1;
int memory[MAX][MAX];

int edit(int i, int j) {
	if (i == (int) str1.size())
		return (int) str2.size() - j;  

     if (j == (int) str2.size())
         return (int) str1.size() - i;   

	auto &ret = memory[i][j];
	if (ret != -1)
		return ret;

	if (str1[i] == str2[j])
		return ret = edit(i + 1, j + 1);

	int delete_ = 1 + edit(i + 1, j);
	int insert = 1 + edit(i, j + 1);
	int change = 1 + edit(i + 1, j + 1);
	return ret = min(min(insert, delete_), change);
}

class Solution {
public:
	int minDistance_(string text1, string text2) {
		str1 = text1, str2 = text2;

		memset(memory, -1, sizeof(memory));
		return edit(0, 0);
	}
    int minDistance(string text1, string text2)
    {
        int n=text1.size(), m=text2.size();
        vector<vector<int>> memory_(n+1, vector<int> (m+1, 0));
        for(int i=0; i <= n; i++)  
            memory_[i][m] = n-i;
        for(int j=0; j <= m; j++)
            memory_[n][j] = m-j;

        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(text1[i]==text2[j])
                    memory_[i][j] = memory_[i+1][j+1];
                else
                    memory_[i][j] = 1 + min({memory_[i+1][j], memory_[i][j+1], memory_[i+1][j+1] });
            }
        }   
        return memory_[0][0];
    }
};



