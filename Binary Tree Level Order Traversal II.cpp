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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        
        preTravel(ans, root, 0);
        
        for (int i = 0; i < ans.size() / 2; i++)    {
            swap(ans[i], ans[ans.size() - 1 - i]);
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