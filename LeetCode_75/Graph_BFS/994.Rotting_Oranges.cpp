// https://leetcode.com/problems/rotting-oranges/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
    public:
        vector<pair<int,int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} };  
        int orangesRotting(vector<vector<int>>& grid) {
            int rows = grid.size(), cols = grid[0].size();
            queue<pair<int,int>> q;
            int freshCount = 0, minutes = 0;
    
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if(grid[i][j] == 2) q.push({i, j});
                    else if(grid[i][j] == 1) freshCount++;
                }
            }
    
            if(freshCount == 0) return 0;
    
            while(!q.empty()) {
                int size = q.size();
                bool rotted = false;
                while(size--) {
                    auto [x, y] = q.front();
                    q.pop();
                    for(auto [dx, dy] : dir) {
                        int newX = x + dx, newY = y + dy;
                        if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                            grid[newX][newY] = 2;
                            q.push({newX, newY});
                            freshCount--;
                            rotted = true;
                        }
                    }
                }
                if(rotted) minutes++;
            }
            
            return freshCount == 0 ? minutes : -1;
        }
    };
    

int main(){
    vector<vector<int>> grid = { {2,1,1}, {1,1,0}, {0,1,1} };
    cout << Solution().orangesRotting(grid) << endl;
    
    grid = { {2,1,1}, {1,1,0}, {0,1,1} };
    cout << Solution().orangesRotting(grid) << endl;
    
    grid = { {2,1,1}, {0,1,1}, {1,0,1} };
    cout << Solution().orangesRotting(grid) << endl;

    return 0;
}