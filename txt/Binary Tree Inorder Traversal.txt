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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        Travel(ans, root);
        return ans;
    }
    
    void Travel(vector<int> &ans, TreeNode *node)   {
        if (node == NULL)   {
            return;
        }
        else    {
            Travel(ans, node->left);
            ans.push_back(node->val);
            Travel(ans, node->right);
        }
    }
};