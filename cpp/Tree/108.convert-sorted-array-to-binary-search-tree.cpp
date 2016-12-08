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
    TreeNode *dfs(int left, int right, vector<int>& nums) {
        if (left > right) 
        return NULL;
        // 中间节点的位置
        int m = (left +  right) / 2;
        
        // 生成根节点
        TreeNode *tp = new TreeNode(nums[m]);

        // 递归处理左右子树
        tp->left  = dfs(left, m - 1, nums);
        tp->right = dfs(m + 1, right, nums);
        
        // 返回根节点
        return tp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size() - 1, nums);
    }
};
