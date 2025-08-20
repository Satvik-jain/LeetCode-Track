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
    // void helper(TreeNode* p, vector<TreeNode*>& st){
    //     if (!p){
    //         st.push_back(nullptr);
    //         return;
    //     }
    //     st.push_back(p);
    //     helper(p->left, st);
    //     helper(p->right, st);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if ((!p && q)||(p && !q)) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        // vector<TreeNode*> st1, st2;
        // helper(p, st1); helper(q, st2);
        // if (st1.size() != st2.size()) return false;
        // for (int i = 0; i < st1.size(); i++){
        //     if(!st1[i] && !st2[i]) continue;
        //     if ((!st1[i] && st2[i])||(st1[i] && !st2[i])) return false;
        //     if (st1[i]->val != st2[i]->val) return false;
        // }
        // return true;
    }
};