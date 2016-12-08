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
    int calcTreeSize(TreeNode* root){
        if (NULL == root)
        return 0;
        return 1 + calcTreeSize(root->left) + calcTreeSize(root->right);
    }
   
public:
    int kthSmallest(TreeNode* root, int k) {
        if (NULL == root){
            return 0;
        }
        int leftTreeSize = calcTreeSize(root->left);
        if (leftTreeSize+1 == k){
            return root->val;
        }
        else if (leftTreeSize >= k){
            return kthSmallest(root->left, k);
        }
        else{
            return kthSmallest(root->right, k-leftTreeSize-1);
        }
    }
};
