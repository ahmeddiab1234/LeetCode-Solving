// https://leetcode.com/problems/daily-temperatures/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

class Stack {
private:
    int size { };
    int top { };
    int* array { };
public:
    Stack(int size) :
            size(size), top(-1) {
        array = new int[size];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int x) {
        assert(!isFull());
        array[++top] = x;
    }

    int pop() {
        assert(!isEmpty());
        return array[top--];
    }

    int peek() {
        assert(!isEmpty());
        return array[top];
    }

    int isFull() {
        return top == size - 1;
    }

    int isEmpty() {
        return top == -1;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";
    }

    
};


class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        Stack st(n);

        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && temperatures[i] > temperatures[st.peek()]) 
            {
                int prevIndex = st.peek();
                st.pop();
                res[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }

        return res;
    }
};





