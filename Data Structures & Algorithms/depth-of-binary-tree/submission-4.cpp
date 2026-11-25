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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int maxd = 1;
        while(!st.empty())
        {
            auto [node, d] = st.top();
            st.pop();
            maxd = max(maxd, d);
            if(node->left)
                st.push({node->left, d + 1});
            if(node->right)
                st.push({node->right, d + 1});
        }

        return maxd;
    }
};
