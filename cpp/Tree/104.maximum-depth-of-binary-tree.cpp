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
    int maxDepth(TreeNode* root) 
    {
        if (NULL == root)
        {
            return 0;
        }
        return dfs(root);
    }
    
    int dfs(TreeNode* root)
    {
        if (NULL == root->left && NULL == root->right)
        {
            return 1;
        }
        
        int leftDepth = INT_MIN, rightDepth = INT_MIN;
        
        if (NULL != root->left)
        {
            leftDepth = dfs(root->left) + 1;
        }
        
        if (NULL != root->right)
        {
            rightDepth = dfs(root->right) + 1;
        }
        
        return (leftDepth > rightDepth) ? leftDepth: rightDepth; 
    }
};
