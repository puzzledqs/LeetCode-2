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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidBST(root, -2000000000, 2000000000);
    }
    
    bool isValidBST(TreeNode *root, int mi, int ma) {
        if (root == NULL)
            return true;
        if (root->val >= ma || root->val <= mi)
            return false;
        if (root->left != NULL)    {
            if (!isValidBST(root->left, mi, root->val))
                return false;
        }
        if (root->right != NULL)    {
            if (!isValidBST(root->right, root->val, ma))
                return false;
        }
        return true;
    }
};