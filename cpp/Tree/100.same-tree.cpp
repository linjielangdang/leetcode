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
    vector<int> pVec, qVec;
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int>::iterator pIter, qIter;
        if (NULL==p && NULL==q)
        {
            return true;
        }
        traverse(p, pVec);
        traverse(q, qVec);
        pIter = pVec.begin();
        qIter = qVec.begin();
        if (pVec.size() != qVec.size())
        {
            return false;
        }
        while (pIter != pVec.end())
        {
            if (*pIter != *qIter)
            {
                return false;
            }
            ++pIter;
            ++qIter;
        }
        return true;
    }
    
    void traverse(TreeNode* root, vector<int>& ivec)
    {
        if (NULL == root)
        {
            ivec.push_back(0);
            return ;
        }
        ivec.push_back(root->val);
        traverse(root->left, ivec);
        traverse(root->right, ivec);
    }
};
