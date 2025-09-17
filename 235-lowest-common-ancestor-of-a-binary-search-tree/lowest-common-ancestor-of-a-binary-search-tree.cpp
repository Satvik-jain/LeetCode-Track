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
    void getpath(TreeNode* root, vector<TreeNode*>& v, TreeNode* p, int &found){
        if (!root) return;
        if (root == p){
            v.push_back(root);
            found = 1;
            return;
        }
        if (!found) getpath(root->left, v, p, found);
        if (!found) getpath(root->right, v, p, found);
        if (found) v.push_back(root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2; int found = 0;
        getpath(root, p1, p, found); found = 0;
        getpath(root, p2, q, found);
        TreeNode* ans;
        reverse(p1.begin(), p1.end());
        reverse(p2.begin(), p2.end());
        for (int i = 0; i < min(p1.size(), p2.size()); i++){
            if (p1[i] == p2[i]) ans = p1[i];
            else break;
        }
        return ans;
    }
};