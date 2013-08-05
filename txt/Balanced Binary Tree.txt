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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)  {
            return true;
        }
        
        int tmp;
        return Check(root, tmp);
    }
    
    bool Check(TreeNode *root, int &h)  {
        if (root == NULL)   {
            h = 0;
            return true;
        }
        int left, right;
        bool p1, p2;
        p1 = Check(root->left, left);
        p2 = Check(root->right, right);
        h = max(left, right) + 1;
        if (!p1 || !p2)
            return false;
        if (abs(left - right) > 1)
            return false;
        return true;
    }
};