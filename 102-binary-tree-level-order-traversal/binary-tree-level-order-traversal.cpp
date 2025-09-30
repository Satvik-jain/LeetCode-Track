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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return {};
        vector<vector<int>> ans;
        q.push(root);
        vector<int> layer;
        TreeNode* last = q.front();
        while(!q.empty()){
            TreeNode* node = q.front();
            int val = node->val;
            q.pop();
            layer.push_back(val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if (node == last){
                ans.push_back(layer); 
                last = q.back();
                layer.clear();
            }
        }
        return ans;
    }
};