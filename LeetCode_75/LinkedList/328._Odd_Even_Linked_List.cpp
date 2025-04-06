// https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) 
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        return head;
    }
};


void printList(ListNode* head) 
{
    while (head) 
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
    
int main() 
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.oddEvenList(head);
    printList(head);
    cout << endl;
    
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(5);
    head2->next->next->next->next = new ListNode(6);
    head2->next->next->next->next->next = new ListNode(4);
    head2->next->next->next->next->next->next = new ListNode(7);
    head2 = sol.oddEvenList(head2);
    printList(head2);
    cout << endl;

    return 0;
}