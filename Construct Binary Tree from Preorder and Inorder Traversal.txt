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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() == 0)
            return NULL;
        
        TreeNode *now = new TreeNode(preorder[0]);
        
        int p = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        if (p == 0)   {
            now->left = NULL;
            now->right = buildTree(vector<int>(preorder.begin() + 1, preorder.end), vector<int>(inorder.begin() + 1, inorder.end));
        }
        else    {
            int q = find(preorder.begin(), preorder.end(), inorder[p - 1]) - preorder.begin();
            now->left = buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + q), vector<int>(inorder.begin() + 1, inorder.end));
        }
        
        return now;
    }
    
    int findint(vector<int> v, int n)  {
        for (int i = 0; i < v.size(); i++)  {
            if (v[i] == n)  {
                return i;
            }
        }
        return -1;
    }
};