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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int ans = -0x7FFFFFFF;
        Travel(root, ans);
        
        return ans;
    }
    
    int Travel(TreeNode *root, int &ans)   {
        if (root == NULL)
            return 0;
            
        int left = Travel(root->left, ans);
        int right = Travel(root->right, ans);
        
        ans = max(ans, max(left, 0) + max(right, 0) + root->val);
        
        return max(max(left, right), 0) + root->val;
    }
};