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
private:
    vector<int> ret;
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if (NULL == root)
        {
            return ret;
        }
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
        return ret;
    }
};
