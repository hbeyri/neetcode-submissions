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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(true)
        {
            while(node)
            {
                st.push(node);
                node = node->left;
            }

            --k;
            node = st.top();
            st.pop();
            if(k==0)
                return node->val;

            node = node->right;
        }

        return -1;
    }
};
