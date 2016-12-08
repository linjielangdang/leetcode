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
    TreeNode* invertTree(TreeNode* root) 
    {
        if (NULL == root)
        return NULL;
        
        if (NULL == root->left && NULL == root->right)
        {
            return root;
        }
        
        TreeNode* left;
        TreeNode* right;
        if (NULL != root->left || NULL != root->right)
        {
            left = root->right;
            right = root->left;
            root->left = invertTree(left);
            root->right = invertTree(right);
        }
        
        return root;
    }
};
