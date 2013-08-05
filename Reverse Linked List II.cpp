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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (m == n)
            return head;
        
        ListNode *pre = new ListNode(0), *now = head;
        pre->next = head;
        head = pre;
        
        for (int i = 1; i < m; i++) {
            pre = now;
            now = now->next;
        }
        
        ListNode *nn = now->next;
        for (int i = m + 1; i <= n; i++)    {
            ListNode *tmp = nn->next;
            nn->next = now;
            now = nn;
            nn = tmp;
        }
        
        pre->next->next = nn;
        pre->next = now;
        
        return head->next;
    }
};