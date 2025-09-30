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
    bool is_same(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;
        if ((!p && q) || (p && !q)) return false;
        if (p->val != q->val) return false;
        return is_same(p->left, q->left) && is_same(p->right, q->right);
    }
    bool find(TreeNode* root, TreeNode* subRoot){
        if (!root) return false;
        bool if_same = false;
        if (root->val == subRoot->val){
            if_same = is_same(root, subRoot);
        }
        return if_same || find(root->right, subRoot) || find(root->left, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return find(root, subRoot);
    }
};