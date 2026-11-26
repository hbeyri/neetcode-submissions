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
    unordered_map<int, int> in_map;

    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end)
    {
        TreeNode* root = new TreeNode(preorder[pre_start++]);
        int in_root_idx = in_map[root->val];

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

        for(int i=0;i<inorder.size();++i)
            in_map[inorder[i]] = i;

        return recurse(preorder, inorder, 0, inorder.size()-1);
    }
};
