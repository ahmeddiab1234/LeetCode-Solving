// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        while(a||b||c){
            int bin_a = a&1, bin_b = b&1, bin_c = c&1;
            if (bin_c == 1) {
                if (bin_a == 0 && bin_b == 0) cnt += 1;
            } else {
                if (bin_a == 1 && bin_b == 1) cnt += 2;
                else if (bin_a == 1 || bin_b == 1) cnt += 1;
            }
            a >>=1, b>>=1, c>>=1;
        }
        return cnt;
    }
};

int main(){

    cout << Solution().minFlips(2, 6, 5) << endl;
    cout << Solution().minFlips(4, 2, 7) << endl;

    return 0;
}

