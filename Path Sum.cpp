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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL)
            return false;
        else
            return hasPathSum(root, sum, true);    
    }
    
    bool hasPathSum(TreeNode *root, int sum, bool k) {
        if (root == NULL)   {
            return false;
        }
        
        if (root->left == NULL && root->right == NULL)  {
            if (root->val == sum)
                return true;
            else 
                return false;
        }
        
        return hasPathSum(root->left, sum - root->val, true) ||  hasPathSum(root->right, sum - root->val, true);   
    }    
};