class Solution {
  public:
    void helper(TreeNode* root, vector<string>& ans, string &v){
        if (!root) return;
        int len = v.length();
        v+=to_string(root->val);
        if (!root->left && !root->right){
            ans.push_back(v);
            v.resize(len);
            return;
        }
        v+="->";
        helper(root->left, ans, v);
        helper(root->right, ans, v);
        v.resize(len);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string v;
        if (!root) return {};
        helper(root, ans, v);
        return ans;
    }
};