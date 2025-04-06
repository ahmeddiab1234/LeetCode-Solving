// https://leetcode.com/problems/combination-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            if (i > n) break; 
            current.push_back(i);
            backtrack(i + 1, k, n - i, current, result); 
            current.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, k, n, current, result);
        return result;
    }
};

int main(){
    vector<vector<int>> res = Solution().combinationSum3(3, 7);
    for(auto i:res){
        for(int j:i){
            cout << j << ' ';
        }
    }

    cout << endl;
    res = Solution().combinationSum3(3, 9);
    for(auto i:res){
        for(int j:i){
            cout << j << ' ';
        }
    }

    return 0;
}
