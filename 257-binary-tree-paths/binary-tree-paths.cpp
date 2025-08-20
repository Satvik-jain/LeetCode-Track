class Solution {
  public:
    void helper(TreeNode* root, vector<string>& ans, string v){
        if (!root) return;
        v+=to_string(root->val);
        if (!root->left && !root->right){
            ans.push_back(v);
            return;
        }
        v+="->";
        helper(root->left, ans, v);
        helper(root->right, ans, v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string v;
        if (!root) return {};
        helper(root, ans, v);
        return ans;
    }
};