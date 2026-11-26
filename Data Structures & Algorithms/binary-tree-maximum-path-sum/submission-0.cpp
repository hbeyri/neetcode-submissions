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
    int maxsum = 0;

    int recurse(TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            maxsum = max(maxsum, root->val);
            return root->val;
        }

        int sum = root->val;
        int left = 0;
        int right = 0;
        if(root->left)
        {
            left = recurse(root->left);
            sum = max(sum, left + sum);
        }
        if(root->right)
        {
            right = recurse(root->right);
            sum = max(sum, right + sum);
        }
        maxsum = max(maxsum, sum);
        int A = root->val;
        int B = A + left;
        int C = A + right;
        return max({A, B, C});
    }

    int maxPathSum(TreeNode* root) {
        maxsum = root->val;
        recurse(root);
        return maxsum;
    }
};
