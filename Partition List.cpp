/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL)
            return head;
        
        ListNode *small = new ListNode(0), *shead = small;
        ListNode *pre = new ListNode(0), *now = head;
        pre->next = head;
        head = pre;
        
        while (now != NULL) {
            if (now->val < x)   {
                small->next = now;
                small = small->next;
                now = now->next;
                pre->next = now;
            }
            else    {
                pre = now;
                now = now->next;
            }
        }
        
        small->next = head->next;
        
        return shead->next;
    }
};