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
    tuple<bool, int, int> recurse(TreeNode* root)
    {
        if(!root)
            return {true, INT_MIN, INT_MAX};
        if(!root->left && !root->right)
            return {true, root->val, root->val};
        int min_v = root->val;
        int max_v = root->val;
        if(root->left)
        {
            auto[from_left, left_minv, left_maxv] = recurse(root->left);
            if(!from_left || root->val <= left_maxv)
                return {false, INT_MIN, INT_MAX};
            min_v = left_minv;
        }
        if(root->right)
        {
            auto[from_right, right_minv, right_maxv] = recurse(root->right);

            if(!from_right || root->val >= right_minv)
                return {false, INT_MIN, INT_MAX};
            max_v = right_maxv;
        }

        return {true, min_v, max_v};
    }

    bool isValidBST(TreeNode* root) {
        auto [valid, minv, maxv] = recurse(root);
        return valid;
    }
};
