/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int &sum){
        if (!root) return 0;
        int left = helper(root->left, sum);
        int right = helper(root->right, sum);
        sum = max({sum, left+right+root->val, root->val, left + root->val, right + root->val});
        return max({left, right, 0}) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        helper(root, sum);
        return sum;
    }
};