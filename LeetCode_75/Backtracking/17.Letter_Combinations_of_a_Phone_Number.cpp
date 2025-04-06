// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void backtrake(unordered_map<char,string>& phone, string& digits, string& word, vector<string>& res, int idx){
        if(idx==digits.size()){
            if(!word.empty())
                res.push_back(word);
            return;
        }
        for(char ch: phone[digits[idx]]){
            word.push_back(ch);
            backtrake(phone, digits, word, res, idx+1);
            word.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pgrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        string word="";
        vector<string> res;
        backtrake(phone, digits, word, res, 0);
        return res;
    }
};

int main(){
    string str1 = "23";
    vector<string> res = Solution().letterCombinations(str1);
    for(auto s: res){
        cout << s << ' ';
    }
    cout << endl;
    str1 = "";
    res = Solution().letterCombinations(str1);
    for(auto s: res){
        cout << s << ' ';
    }
    cout << endl;
    str1 = "2";
    res = Solution().letterCombinations(str1);
    for(auto s: res){
        cout << s << ' ';
    }
    cout << endl;

    return 0;
}

/*
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Input: digits = ""
Output: []
Input: digits = "2"
Output: ["a","b","c"]
*/