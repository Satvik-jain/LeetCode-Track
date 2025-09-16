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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) return node;
        TreeNode* ans = root;
        TreeNode* prev = root;
        int side = 0; // 0 for left
        while(root){
            if (root->val > val){
                prev = root;
                root = root->left;
                side = 0;
            }
            else{
                prev = root;
                root = root->right;
                side = 1;
            }
        }
        if (!side) prev->left = node;
        else prev->right = node;
        return ans;
    }
};