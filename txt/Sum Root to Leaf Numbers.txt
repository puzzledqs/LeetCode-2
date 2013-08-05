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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int ans = 0;
        
        Travel(root, ans, 0);
        
        return ans;
    }
    
    void Travel(TreeNode *root, int &ans, int now)   {
        if (!root)
            return;
            
        now = now * 10 + root->val;
        if (!root->left && !root->right)    {
            ans += now;
        }
        Travel(root->left, ans, now);
        Travel(root->right, ans, now);
    }
};