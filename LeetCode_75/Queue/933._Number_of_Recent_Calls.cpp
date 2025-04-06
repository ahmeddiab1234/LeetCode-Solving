// https://leetcode.com/problems/number-of-recent-calls/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<queue>
using namespace std;


class RecentCounter 
{
    private:
        int *array = new int[1000];
        int front=0, rear=0;

    public:
        RecentCounter() {}
        
        int ping(int t) 
        {
            while(rear > front && (t-array[front] > 3000))
            {
                front++;
            }
            array[rear++] = t;
            return rear-front;
        }
};
    
int main()
{
    RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(1);
    cout << param_1 << endl;
    int param_2 = obj->ping(100);
    cout << param_2 << endl;
    int param_3 = obj->ping(3001);
    cout << param_3 << endl;
    int param_4 = obj->ping(3002);
    cout << param_4 << endl;

    return 0;
}
/*
Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

*/