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
    tuple<int, int, bool> getMinMax(TreeNode* root)
    {
        if(!root->left && !root->right)
            return {root->val, root->val, true};
        
        int minval = root->val;
        int maxval = root->val;
        if(root->left)
        {
            auto [min_left, max_left, is_bst] = getMinMax(root->left);
            if(!is_bst || max_left >= root->val)
                return {-1, -1, false};
            minval = min_left;
        }

        if(root->right)
        {
            auto [min_right, max_right, is_bst] = getMinMax(root->right);
            if(!is_bst || min_right <= root->val)
                return {-1, -1, false};
            maxval = max_right;
        }

        return {minval, maxval, true};
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        auto[minval, maxval, is_bst] = getMinMax(root);
        return is_bst;
    }
};
