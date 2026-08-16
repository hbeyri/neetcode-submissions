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
    // recursive
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(!root)
    //         return nullptr;

    //     if(max(p->val, q->val)<root->val)
    //         return lowestCommonAncestor(root->left, p, q);
    //     else if(min(p->val, q->val)>root->val)
    //         return lowestCommonAncestor(root->right, p, q);
    //     else
    //         return root;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while(node)
        {
            if(max(p->val, q->val) < node->val)
                node = node->left;
            else if(min(p->val, q->val) > node->val)
                node = node->right;
            else
                return node;
        }
        return nullptr;
    }
};
