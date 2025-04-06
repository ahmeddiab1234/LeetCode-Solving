// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
    public:
        vector<pair<int, int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} };    
    
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            int m = maze.size(), n = maze[0].size();
            queue<pair<int, int>> q;
            q.push({entrance[0], entrance[1]});
            maze[entrance[0]][entrance[1]] = '+'; 
            int steps = 0;
    
            while (!q.empty()) {
                int sz = q.size();
                steps++;
                while (sz--) {
                    auto [x, y] = q.front();
                    q.pop();
    
                    for (auto [dx, dy] : dir) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                            if (nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1)
                                return steps;  
                            maze[nx][ny] = '+';  
                            q.push({nx, ny});
                        }
                    }
                }
            }
            return -1;
        }
    };
    

int main(){
    vector<vector<char>> maze = { {'+','+','.','+'}, {'.','.','.','+'}, {'+','+','+','.'} };
    vector<int> entrance = {1,2};
    cout << Solution().nearestExit(maze, entrance) << endl;

    maze = { {'+','+','+'}, {'.','.','.'}, {'+','+','+'} };
    entrance = {1,0};
    cout << Solution().nearestExit(maze, entrance) << endl;

    return 0;
}
/*
Input: maze = [['+','+','.','+'],['.','.','.','+'],['+','+','+','.']], entrance = [1,2]
Output: 1

Input: maze = [['+','+','+'],['.','.','.'],['+','+','+']], entrance = [1,0]
Output: 2
*/