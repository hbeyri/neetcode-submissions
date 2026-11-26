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
    int pre_start = 0;
    int pre_end = 0;

    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end)
    {
        if(pre_start>pre_end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[pre_start++]);
        int in_root_idx = -1;
        for(int i=in_start;i<=in_end;++i)
        {
            if(root->val == inorder[i])
            {
                in_root_idx = i;
                break;
            }
        }

        if(in_root_idx > in_start)
        {
            // we have left sub-tree
            root->left = recurse(preorder, inorder, in_start, in_root_idx-1);
        }

        if(in_root_idx < in_end)
        {
            // we have right sub-tree
            root->right = recurse(preorder, inorder, in_root_idx+1, in_end);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_start = 0;
        pre_end = preorder.size()-1;
        return recurse(preorder, inorder, 0, inorder.size()-1);
    }
};
