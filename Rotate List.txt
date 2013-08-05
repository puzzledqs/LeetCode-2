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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL)
            return head;
        
        int n = 1;
        ListNode *p = head;
        while (p->next != NULL) {
            p = p->next;
            n++;
        }
        
        if (n == 1) {
            return head;
        }
        
        k = k % n;
        
        if (k == 0) {
            return head;
        }
        
        ListNode *tail = p;
        
        p = head;
        for (int i = 0; i < n - k - 1; i++) {
            p = p->next;
        }
        
        //split from p
        ListNode *tmp = p->next;
        tail->next = head;
        head = tmp;
        p->next = NULL;
        
        return head;
    }
};