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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ans = new ListNode(0);
        ListNode *now = ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0)    {
            int tmp = carry;
            if (l1 != NULL) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                tmp += l2->val;
                l2 = l2->next;
            }
            now->next = new ListNode(0);
            now = now->next;
            now->val = tmp % 10;
            carry = tmp / 10;
        }
        return ans->next;
    }
};