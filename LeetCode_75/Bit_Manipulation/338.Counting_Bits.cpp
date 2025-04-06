// https://leetcode.com/problems/counting-bits/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        
        for(int i=0; i<=n; i++){
            int cnt=0;
            int num=i;
            while(num){
                cnt += num&1;
                num >>=1;
            }
            res[i]=cnt;
        }
        return res;
    }
};

int main(){
    int n=2;
    vector<int> res = Solution().countBits(n);
    for(int i:res){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}