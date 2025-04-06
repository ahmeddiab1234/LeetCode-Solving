// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void build_graph(vector<vector<pair<int, int>>>& graph, int from, int to) {
            graph[from].push_back({to, 1});
            graph[to].push_back({from, 0}); 
        }
    
        void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& vis, int& cnt) {
            vis[node] = true;
            for (auto& [neighbor, is_original] : graph[node]) {
                if (!vis[neighbor]) {
                    cnt += is_original; 
                    dfs(neighbor, graph, vis, cnt);
                }
            }
        }
    
        int minReorder(int n, vector<vector<int>>& connections) {
            vector<vector<pair<int, int>>> graph(n); 
            for (auto& edge : connections) {
                int a = edge[0];
                int b = edge[1];
                build_graph(graph, a, b);
            }
    
            vector<bool> vis(n, false);
            int cnt = 0;
            dfs(0, graph, vis, cnt);
            return cnt;
        }
};


int main(){
    vector<vector<int>> graph = { {0,1}, {1,3}, {2,3}, {4,0}, {4,5} };
    int n= graph.size() +1;
    cout << Solution().minReorder(n, graph) << endl;
    
    graph = { {1,0}, {1,2}, {3,2}, {3,4} };
    n= graph.size() +1;
    cout << Solution().minReorder(n, graph) << endl;
    
    graph = { {1,0}, {2,0} };
    n= graph.size() +1;
    cout << Solution().minReorder(n, graph) << endl;

    return 0;    
}