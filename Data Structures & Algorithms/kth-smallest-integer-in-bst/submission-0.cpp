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
    stack<TreeNode*> st;

    void leftMost(TreeNode* node)
    {
        st.push(node);
        while(true)
        {
            if(node->left)
            {
                node = node->left;
                st.push(node);
            }
            else
                break;
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        leftMost(root);

        while(k>1)
        {
            --k;
            TreeNode* node = st.top();
            st.pop();
            if(node->right)
            {
                leftMost(node->right);
            }
        }
        return st.top()->val;
    }
};
