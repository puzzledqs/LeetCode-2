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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        
        preTravel(ans, root, 0);
        
        for (int i = 1; i < ans.size(); i += 2) {
            for (int j = 0; j < ans[i].size() / 2; j++)    {
                swap(ans[i][j], ans[i][ans[i].size() - 1 - j]);
            }
        }
        
        return ans;
    }
    
    void preTravel (vector<vector<int> > &ans, TreeNode *root, int level)   {
        if (root == NULL)
            return;
        while (level >= ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        preTravel(ans, root->left, level + 1);
        preTravel(ans, root->right, level + 1);
    }
};