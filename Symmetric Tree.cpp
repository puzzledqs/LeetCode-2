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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return true;
        else
            return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *r1, TreeNode *r2) {
        if (r1 == NULL && r2 == NULL)
            return true;
        else if ((r1 == NULL || r2 == NULL))    {
            return false;
        }
        else if (r1->val != r2->val)    {
            return false;
        }
        else    {
            return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
        }
    }
};