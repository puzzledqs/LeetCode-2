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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return makeTree(num, 0, num.size() - 1);
    }
    
    TreeNode *makeTree(vector<int> &num, int p, int q) {
        if (p > q) 
            return NULL;
        
        int m = (p + q) / 2;
        TreeNode *t = new TreeNode(num[m]);
        t->left = makeTree(num, p, m - 1);
        t->right = makeTree(num, m + 1, q);
    }
};