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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return makeTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode *makeTree(vector<int> &postorder, vector<int> &inorder, int pi, int pj, int qi, int qj)    {
        if (pi > pj)
            return NULL;
        
        TreeNode *now = new TreeNode(postorder[pj]);
        
        int pos = findint(inorder, qi, qj, postorder[pj]);
        int len = pos - qi;
        
        now->left = makeTree(postorder, inorder, pi, pi + len - 1, qi, qi + len - 1);
        now->right = makeTree(postorder, inorder, pi + len, pj - 1, qi + len + 1, qj);
        
        return now;
    }
    
    int findint(vector<int> &v, int s, int e, int n)  {
        for (int i = s; i <= e; i++)  {
            if (v[i] == n)  {
                return i;
            }
        }
        return -1;
    }
};