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
    int helper(TreeNode* root, bool &ans){
        if (!root) return 0;
        int left = 1+helper(root->left, ans);
        int right = 1+helper(root->right, ans);
        ans = ans && (abs(left-right)<=1);
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root, ans);
        return ans;
    }
};