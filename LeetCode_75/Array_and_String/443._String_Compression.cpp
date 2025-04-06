// https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int compress(vector<char>& chars) 
    {
        int write = 0, count = 1;
        int n = chars.size();

        for (int i = 1; i <= n; i++) 
        {
            if (i < n && chars[i] == chars[i - 1]) 
            {
                count++;
            } 
            else 
            {
                chars[write++] = chars[i - 1];  
                if (count > 1) 
                {  
                    for (char c : to_string(count)) 
                    {
                        chars[write++] = c;
                    }
                }
                count = 1;
            }
        }
        return write;
    }

};

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << Solution().compress(chars) << endl;   

    chars = {'a'};
    cout << Solution().compress(chars) << endl;   

    chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << Solution().compress(chars) << endl;   

    return 0;
}
