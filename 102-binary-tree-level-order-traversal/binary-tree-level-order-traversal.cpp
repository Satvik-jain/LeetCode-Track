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
        vector<vector<int>> ans;
        vector<int> v;
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int k = 1;
        TreeNode* temp;
        while(!q.empty()&&k){
            temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            k--;
            if (k==0){
                k = q.size();
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};