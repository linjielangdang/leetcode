/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(NULL == root)
        {
            return 0;
        }
        if(NULL != root->left && NULL != root->right)
        {
           return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        else if(NULL == root->left)
        {
            return 1 + minDepth(root->right);
        }
        else
        {
            return 1 + minDepth(root->left);
        }
    }
};
