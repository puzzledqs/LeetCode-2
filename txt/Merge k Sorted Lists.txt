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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<ListNode*, vector<ListNode*>, Solution> heap;
        ListNode *ans = new ListNode(0), *now = ans;
        
        for (int i = 0; i < lists.size(); i++)    {
            if (lists[i] != NULL)   {
                heap.push(lists[i]);
            }
        }
        
        while (!heap.empty())   {
            ListNode *k = heap.top();
            heap.pop();
            now->next = k;
            now = now->next;
            if (k->next != NULL)    {
                heap.push(k->next);
            }
        }
        
        return ans->next;
    }
    
    bool operator() (const ListNode* lhs, const ListNode* rhs) const    {
        return lhs->val > rhs->val;
    }
};