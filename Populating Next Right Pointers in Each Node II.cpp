/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeLinkNode*> stackNode;
        queue<int> stackDepth;
        
        if (root == NULL)
            return;
            
        stackNode.push(root);
        stackDepth.push(1);
        
        TreeLinkNode *preNode = NULL, *nowNode;
        int preDepth = 0, nowDepth;
        while (!stackNode.empty())    {
            nowNode = stackNode.front();
            nowDepth = stackDepth.front();
            stackNode.pop();
            stackDepth.pop();
            
            if (preNode != NULL)    {
                if (preDepth == nowDepth)   {
                    preNode->next = nowNode;
                }
                else    {
                    preNode->next = NULL;
                }
            }
            
            if (nowNode->left != NULL)  {
                stackNode.push(nowNode->left);
                stackDepth.push(nowDepth + 1);
            }
            
            if (nowNode->right != NULL)  {
                stackNode.push(nowNode->right);
                stackDepth.push(nowDepth + 1);
            }
            
            preNode = nowNode;
            preDepth = nowDepth;
        }
        
        if (preNode != NULL)    {
            preNode->next = NULL;
        }
    }
};