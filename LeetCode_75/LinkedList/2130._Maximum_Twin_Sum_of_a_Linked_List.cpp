// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    
    public:
        ListNode* reverseList(ListNode* head) 
        {
            ListNode* prev = nullptr;
            ListNode* cur = head;
            while(cur)
            {
                ListNode* after = cur->next;
                cur->next = prev;
                prev = cur;   
                cur = after;
            }
            return prev;  
        }
        int pairSum(ListNode* head) 
        {
            if (!head) return 0;
    
            ListNode *slow = head, *fast = head;
            while (fast && fast->next) 
            {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode* secondHalf = reverseList(slow);
            ListNode* firstHalf = head;
            int maxTwinSum = 0;
    
            while (secondHalf) 
            {
                maxTwinSum = max(maxTwinSum, firstHalf->val + secondHalf->val);
                firstHalf = firstHalf->next;
                secondHalf = secondHalf->next;
            }
            return maxTwinSum;
        }
};

int main() 
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;
    cout << sol.pairSum(head) << endl; // 6

    return 0;
}