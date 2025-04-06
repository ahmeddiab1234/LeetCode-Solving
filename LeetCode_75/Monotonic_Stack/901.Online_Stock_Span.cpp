// https://leetcode.com/problems/online-stock-span/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

struct Pair 
{
    int price;
    int span;
};

class Stack 
{
private:
    int size { };
    int top { };
    Pair* array { };
public:
    Stack(int size) : size(size), top(-1) 
    {
        array = new Pair[size];
    }

    ~Stack() 
    {
        delete[] array;
    }

    void push(Pair x) 
    {
        assert(!isFull());
        array[++top] = x;
    }

    Pair pop() 
    {
        assert(!isEmpty());
        return array[top--];
    }

    Pair peek() 
    {
        assert(!isEmpty());
        return array[top];
    }

    bool isFull() 
    {
        return top == size - 1;
    }

    bool isEmpty() 
    {
        return top == -1;
    }
};

class StockSpanner 
{
    Stack st {10000};

public:
    StockSpanner() { }

    int next(int price) 
    {
        int span = 1;
        while (!st.isEmpty() && st.peek().price <= price) 
        {
            span += st.pop().span;
        }
        st.push({price, span});
        return span;
    }
};

int main()
{
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl; 
    cout << obj->next(85) << endl;
    return 0;
}
