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
    int helper(TreeNode* root, int& ans){
        if (!root) return -1;
        int left = 1+helper(root->left, ans);
        int right = 1+helper(root->right, ans);
        ans = max(ans, left+right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};