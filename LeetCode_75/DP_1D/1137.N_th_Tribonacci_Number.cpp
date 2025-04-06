// https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 500+1;
int Memory[MAX];

class Solution {
    int solve(int idx){
        if(idx==1 || idx==2){
            return 1;
        }
        if(idx<=0){
            return 0;
        }
        int& ret = Memory[idx];
        if(ret !=-1){
            return ret;
        }
        ret = solve(idx-1) + solve(idx-2) + solve(idx-3);
        return ret;
    }
    public:
        int tribonacci(int n) {
            memset(Memory, -1, sizeof(Memory));
            return solve(n);
        }
};
    
int main(){
    cout << Solution().tribonacci(4) << endl;
    cout << Solution().tribonacci(3) << endl;

    return 0;
}

