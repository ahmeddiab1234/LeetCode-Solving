// https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        void dfs(int idx, vector<vector<int>>& graph, vector<bool>& visited){
            visited[idx]= true;
            int n=graph.size();
            for(int i=0; i<n; i++){
                if(graph[idx][i]==1 && !visited[i]) dfs(i, graph, visited);
            }
        }
        
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n=isConnected.size();
            vector<bool> visited(n);
            int cnt=0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    cnt++;
                    dfs(i, isConnected, visited);
                }
            }
            return cnt;
        }
};

int main(){
    vector<vector<int>> is_con = { {1,1,0}, {1,1,0}, {0,0,1} };
    cout << Solution().findCircleNum(is_con) << endl;
    is_con = { {1,0,0}, {0,1,0}, {0,0,1} };
    cout << Solution().findCircleNum(is_con) << endl;


    return 0;
}
