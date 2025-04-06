// https://leetcode.com/problems/evaluate-division/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        struct Edge {
            string to;
            double val;
            Edge(string to, double val) : to(to), val(val) {}
        };
    
        unordered_map<string, vector<Edge>> buildGraph(vector<vector<string>>& eq, vector<double>& val) {
            unordered_map<string, vector<Edge>> graph;
            for (int i = 0; i < eq.size(); i++) {
                string from = eq[i][0];
                string to = eq[i][1];
                double v = val[i];
                graph[from].emplace_back(to, v);
                graph[to].emplace_back(from, 1.0 / v);
            }
            return graph;
        }
    
        bool dfs(unordered_map<string, vector<Edge>>& graph, unordered_set<string>& visited, string current, string target, double& product) {
            
            if (current == target) return true;
            visited.insert(current);
            
            for (auto& edge : graph[current]) {
                if (visited.find(edge.to) == visited.end()) {
                    double new_product = product * edge.val;
                    if (dfs(graph, visited, edge.to, target, new_product)) {
                        product = new_product;
                        return true;
                    }
                }
            }
            
            return false;
        }
    
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            auto graph = buildGraph(equations, values);
            vector<double> res;
            
            for (auto& query : queries) {
                string from = query[0];
                string to = query[1];

                if (graph.find(from) == graph.end() || graph.find(to) == graph.end()) {
                    res.push_back(-1.0);
                    continue;
                }
                
                if (from == to) {
                    res.push_back(1.0);
                    continue;
                }
                
                unordered_set<string> visited;
                double product = 1.0;
                if (dfs(graph, visited, from, to, product)) {
                    res.push_back(product);
                } else {
                    res.push_back(-1.0);
                }
            }
            
            return res;
        }
    };
    

int main(){
    vector<vector<string>> equ = { {"a","b"}, {"b","c"} };
    vector<double> val = {2.0,3.0};
    vector<vector<string>> que = { {"a","c"}, {"b","a"}, {"a","e"}, {"x","x"} };
    vector<double> res = Solution().calcEquation(equ, val, que) ;
    for(int i:res){
        cout << i << ' ';
    }
    cout << endl;
    
    equ = { {"a","b"}, {"b","c"}, {"bc","cd"} };
    val = {1.5,2.5,5.0};
    que = { {"a","c"}, {"c","b"}, {"bc","cd"}, {"cd","bc"} };
    res = Solution().calcEquation(equ, val, que) ;
    for(int i:res){
        cout << i << ' ';
    }
    cout << endl;
    
    equ = { {"a","b"} };
    val = {0.5};
    que = { {"a","b"}, {"b","a"}, {"a","c"}, {"x","y"} };
    res = Solution().calcEquation(equ, val, que) ;
    for(int i:res){
        cout << i << ' ';
    }

    return 0;
}
/*
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
*/