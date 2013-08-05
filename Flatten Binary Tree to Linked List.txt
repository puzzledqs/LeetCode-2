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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL)
            return;
        
        stack<TreeNode*> s;
        TreeNode *head = new TreeNode(0), *pre = head;
        
        s.push(root);
        while(!s.empty())   {
            TreeNode *now = s.top();
            s.pop();
            
            pre->left = NULL;
            pre->right = now;
            pre = now;
            
            if (now->right != NULL) {
                s.push(now->right);
            }
            if (now->left != NULL) {
                s.push(now->left);
            }            
        }
        
        pre->left = pre->right = NULL;
        return;
    }
    
    
};