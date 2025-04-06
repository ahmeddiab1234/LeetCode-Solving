// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

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
        int get_size(ListNode* head) 
        {
            int len = 0;
            ListNode* turn = head;
            while (turn) 
            {
                len++;
                turn = turn->next;
            }
            return len;
        }
    
        ListNode* deleteMiddle(ListNode* head) 
        {
            if (!head || !head->next) return nullptr; 
            
            int mid = get_size(head) / 2;
            ListNode* prev = nullptr;
            ListNode* cur = head;
            for (int i = 0; i < mid; i++) 
            {
                prev = cur;
                cur = cur->next;
            }
            
            prev->next = cur->next;
            delete cur;
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
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution sol;
    head = sol.deleteMiddle(head);
    printList(head);

    return 0;
}