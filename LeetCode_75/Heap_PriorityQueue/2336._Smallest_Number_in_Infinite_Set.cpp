// https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75


#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<queue>
using namespace std;


class SmallestInfiniteSet 
{
    priority_queue<int, vector<int>, greater<int>> prior; 
    set<int> set_nums;
    int next_num = 1;
public:
    SmallestInfiniteSet() {}

    int popSmallest() 
    {
        if (!prior.empty()) 
        {
            int num = prior.top();
            prior.pop();
            set_nums.erase(num);
            return num;
        }
        return next_num++;
    }

    void addBack(int num) 
    {
        if (num < next_num && set_nums.find(num) == set_nums.end()) 
        {
            prior.push(num);
            set_nums.insert(num);
        }
    }
};


int main()
{
    
    SmallestInfiniteSet* obj = new SmallestInfiniteSet();
    int param_1 = obj->popSmallest();
    obj->addBack(3);
    return 0;
}
