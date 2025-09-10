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
    void pre(TreeNode* root, vector<TreeNode*> &st){
        if (!root){
            return;
        }
        st.push_back(root);
        if (root->left) pre(root->left, st);
        if (root->right) pre(root->right, st);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> st;
        pre(root, st);
        TreeNode* head = new TreeNode();
        TreeNode* dummy = head;
        for (auto i: st){
            head->right = i;
            head->left = nullptr;
            head = i;
        }
        root = dummy->right;
    }
};