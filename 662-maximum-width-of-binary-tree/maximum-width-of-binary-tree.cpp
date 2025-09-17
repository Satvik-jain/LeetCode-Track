class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> st;
        st.push({root, 1});
        long long ans = LLONG_MIN;

        while(!st.empty()){
            int it = st.size();
            long long i = st.front().second; // base index of this level
            long long min_index = LLONG_MAX, max_index = LLONG_MIN;

            while(it--){
                TreeNode* node = st.front().first;
                long long index = st.front().second - i + 1;
                min_index = min(min_index, index);
                max_index = max(max_index, index);
                st.pop();
                if(node->left) st.push({node->left, 2*index});
                if(node->right) st.push({node->right, 2*index+1});
            }
            ans = max(ans, max_index - min_index + 1);
        }
        return (int)ans;
    }
};
