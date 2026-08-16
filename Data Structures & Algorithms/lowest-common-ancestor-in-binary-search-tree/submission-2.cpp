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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(root->val == p->val)
            return p;
        else if(root->val == q->val)
            return q;
        TreeNode* left = nullptr, *right = nullptr;
        if(p->val<root->val || q->val<root->val)
            left = lowestCommonAncestor(root->left, p, q);
        if(p->val>root->val || q->val>root->val)
            right = lowestCommonAncestor(root->right, p, q);

        if(left && right)
            return root;
        else if(left)
            return left;
        else
            return right;
    }
};
