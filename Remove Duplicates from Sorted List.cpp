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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *now = head;
        while (now->next != NULL) {
            if (now->val == now->next->val) {
                ListNode *del = now->next;
                now->next = now->next->next;
                delete del;
            }
            else    {
                now = now->next;
            }
        }
        return head;
    }
};