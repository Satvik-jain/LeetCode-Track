class Solution {
public:
    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = helper(root->left);
        if (left == -1) return -1;   // left subtree is unbalanced

        int right = helper(root->right);
        if (right == -1) return -1;  // right subtree is unbalanced

        if (abs(left - right) > 1) return -1; // current node not balanced

        return 1 + max(left, right); // return height if balanced
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};
