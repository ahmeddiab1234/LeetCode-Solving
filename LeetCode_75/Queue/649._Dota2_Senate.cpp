// 

#include<iostream>
#include<queue> 
#include<vector> 
using namespace std;

class Solution 
{
    public:
        string predictPartyVictory(string senate) 
        {
            int n = senate.size();
            queue<int> que_R, que_D;

            for(int i = 0; i < n; i++)
            {
                if(senate[i] == 'R') que_R.push(i);
                else que_D.push(i);
            }

            while(!que_D.empty() && !que_R.empty())
            {
                int r = que_R.front(); que_R.pop();
                int d = que_D.front(); que_D.pop();

                if(r < d) que_R.push(r + n);  
                else que_D.push(d + n);
            }

            return que_R.empty() ? "Dire" : "Radiant";
        }
};


int main()
{
    string senate = "RD";
    cout << Solution().predictPartyVictory(senate) << endl;

    senate = "RDD";
    cout << Solution().predictPartyVictory(senate) << endl;

    return 0;
}

/*
Input: senate = "RD"
Output: "Radiant"

Input: senate = "RDD"
Output: "Dire"
*/
