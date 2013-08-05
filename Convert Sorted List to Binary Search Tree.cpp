/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return createTree(head, NULL);
    }
    
    TreeNode *createTree(ListNode *head, ListNode *end)  {
        if (head == NULL)
            return NULL;
        
        ListNode *mid = head, *tmp = head;
        
        while (true) {
            tmp = tmp->next;
            if (tmp == NULL || tmp == end)
                break;
            tmp = tmp->next;
            if (tmp == NULL || tmp == end)
                break;
            mid = mid->next;
        }
        
        TreeNode *now = new TreeNode(mid->val);
        if (head != mid)
            now->left = createTree(head, mid);
        else
            now->left = NULL;
        if (mid->next != end)
            now->right = createTree(mid->next, end);
        else
            now->right = NULL;
            
        return now;
    }
};