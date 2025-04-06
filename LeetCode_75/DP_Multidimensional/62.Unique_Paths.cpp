// https://leetcode.com/problems/unique-paths/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int row, col;
const int MAX = 100+1;
int memory[MAX][MAX];

class Solution {
public:
    bool vlaid(int r, int c){
        if(r >=0 && r <row && c>=0 && c<col)
            return true;
        return false;
    }

    int dp(int r, int c){
        if(r==row-1 && c==col-1){
            return 1;
        }
        if(!vlaid(r, c)){
            return 0;
        }
        int &ret = memory[r][c];
        if(ret != -1){
            return ret;
        }
        return ret = dp(r+1,c)+dp(r,c+1);
    }

    int uniquePaths(int m, int n) {
        memset(memory, -1, sizeof(memory));
        row=m,col=n;
        return dp(0,0);
    }
};

int main(){
    cout << Solution().uniquePaths(3, 7) << endl;
    cout << Solution().uniquePaths(3, 2) << endl;

    return 0;
}
