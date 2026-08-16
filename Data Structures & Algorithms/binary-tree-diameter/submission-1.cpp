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
    int ret = 0;
    int depth(TreeNode* root)
    {
        if(!root)
            return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right); 
        ret = max(ret, left_depth + right_depth);
        return max(1+left_depth, 1+right_depth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ret;
    }
};
