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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return generate(1, n);
        
    }
    
    vector<TreeNode *> generate(int left, int right)    {
        vector<TreeNode *> ans;
        if (left > right)   {
            ans.push_back(NULL);
            return ans;
        }
        vector<TreeNode *> l;
        vector<TreeNode *> r;
        for (int i = left; i <= right; i++) {
            l = generate(left, i - 1);
            r = generate(i + 1, right);
            for (int j = 0; j < l.size(); j++)  {
                for (int k = 0; k < r.size(); k++)  {
                    TreeNode *now = new TreeNode(i);
                    now->left = l[j];
                    now->right = r[k];
                    ans.push_back(now);
                }
            }
        }
        return ans;
    }
    
};