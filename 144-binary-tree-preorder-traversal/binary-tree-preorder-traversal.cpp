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
    void tr(TreeNode* root, vector<int>&v){
        v.push_back(root->val);
        if (root->left)tr(root->left, v);
        if (root->right)tr(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {} ;
        vector<int>v;
        tr(root, v);
        return v;
    }
};