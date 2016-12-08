/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    void traverse(TreeNode* root, int level, vector<vector<int>> &ret)
    {
        if (!root)
        {
            return ;
        }
        
        if (level > ret.size())
        {
            ret.push_back(vector<int>());
        }
        
        ret[level-1].push_back(root->val);
        traverse(root->left, level+1, ret);
        traverse(root->right, level+1, ret);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {   
        vector<vector<int>> ret;
        traverse(root, 1, ret);
        return ret;
    }
};
