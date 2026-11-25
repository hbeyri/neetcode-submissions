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
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(!root)
    //         return nullptr;
    //     if(root == p)
    //         return p;
    //     if(root==q)
    //         return q;
        
    //     if(max(p->val, q->val) < root->val)
    //         return lowestCommonAncestor(root->left, p, q);
    //     else if(min(p->val, q->val) > root->val)
    //         return lowestCommonAncestor(root->right, p, q);
        
    //     return root;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root)
        {
            if(max(p->val, q->val) < root->val)
                root = root->left;
            else if(min(p->val, q->val) > root->val)
                root = root->right;
            else
                return root;                
        }
        return nullptr;
    }
};
