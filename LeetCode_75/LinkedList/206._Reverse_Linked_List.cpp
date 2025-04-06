// https://leetcode.com/problems/reverse-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

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
    head = sol.reverseList(head);
    printList(head);
    cout << endl;
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    Solution sol2;
    head2 = sol2.reverseList(head2);
    printList(head2);
    cout << endl;

    ListNode* head3 = new ListNode();
    Solution sol3;
    head3 = sol3.reverseList(head3);
    printList(head3);
    cout << endl;



    return 0;
}