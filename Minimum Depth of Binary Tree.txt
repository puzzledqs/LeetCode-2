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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        queue<int> depth;
        depth.push(1);
        q.push(root);
        while (!q.empty())  {
            TreeNode *now = q.front();
            q.pop();
            int d = depth.front();
            depth.pop();
            
            if (now->left == NULL && now->right == NULL)  {
                return d;
            }
            else    {
                if (now->left != NULL) {
                    q.push(now->left);
                    depth.push(d + 1);
                }
                if (now->right != NULL) {
                    q.push(now->right);
                    depth.push(d + 1);
                }
            }
        }
    }
};