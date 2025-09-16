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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        if (!root->right && !root->left) return {root->val};
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            if (!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* temp;
                temp = curr->left;
                if (!temp->right){
                    temp->right = curr;
                    curr = curr->left;
                }
                else while(true){
                    if (temp->right == curr){
                        temp->right = nullptr;
                        ans.push_back(curr->val);
                        curr = curr->right;
                        break;
                    }
                    if (!temp->right){
                        temp->right = curr;
                        curr = curr->left;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
        return ans;
    }
};