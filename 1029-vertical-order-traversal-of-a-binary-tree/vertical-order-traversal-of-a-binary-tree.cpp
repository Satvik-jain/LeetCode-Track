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

    using P = tuple<int, int, int>; // c, r, data

    void helper(TreeNode* root, int col, int row, priority_queue<P, vector<P>, greater<P>>& q){
        if (!root) return;
        q.push({col, row, root->val});
        helper(root->left, col-1, row+1, q);
        helper(root->right, col+1, row+1, q);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int col = 0, row = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        helper(root, col, row, q);
        vector<vector<int>> ans;
        col = get<0>(q.top());
        while(!q.empty()){
            vector<int> temp;
            while(!q.empty() && col == get<0>(q.top())){
                temp.push_back(get<2>(q.top()));
                q.pop();
            }
            if (!q.empty()) col = get<0>(q.top());
            ans.push_back(temp);
        }
        return ans;
    }
};