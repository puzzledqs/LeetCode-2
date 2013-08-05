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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        vector<int> tmp;
        
        DFS(ans, tmp, root, sum);
        
        return ans;
    }
    
    void DFS(vector<vector<int> > &ans, vector<int> &v, TreeNode *root, int sum)  {
        if (root == NULL)
            return;
        
        if (root->left == NULL && root->right == NULL)  {
            if (sum == root->val)   {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        
        v.push_back(root->val);
        DFS(ans, v, root->left, sum - root->val);
        DFS(ans, v, root->right, sum - root->val);
        v.pop_back();
    }
};
