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
    int goodNodes(TreeNode* root) {
        int ret = 0;
        stack<pair<TreeNode*, int>> st;
        st.emplace(root, root->val);

        while(!st.empty())
        {
            auto[node, maxval] = st.top();
            st.pop();

            if(node->val >= maxval )
                ++ret;

            maxval = max(maxval, node->val);
            if(node->left)
                st.emplace(node->left, maxval);
            if(node->right)
                st.emplace(node->right, maxval);
        }

        return ret;
    }
};
