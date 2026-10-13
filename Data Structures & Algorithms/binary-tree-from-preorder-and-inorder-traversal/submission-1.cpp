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
    unordered_map<int, int> in_map;
    int count = 0;
    int preorder_idx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inorder_start_idx, int inorder_end_idx)
    {
        // cout<<preorder_idx<<" "<<inorder_start_idx<<" "<<inorder_end_idx<<endl;
        int preorder_val = preorder[preorder_idx];
        TreeNode* root = new TreeNode(preorder_val);
        ++preorder_idx;
        int root_inorder_idx = in_map[preorder_val];

        // ++count;
        // if(count>4)
        //     return nullptr;
        
        // cout<<root_inorder_idx<<endl;
        if(root_inorder_idx > inorder_start_idx)
        {
            // left exists
            root->left = buildTree(preorder, inorder, inorder_start_idx, root_inorder_idx-1);
        }

        if(root_inorder_idx < inorder_end_idx)
        {
            // right exists
            root->right = buildTree(preorder, inorder, root_inorder_idx+1, inorder_end_idx);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)    
    {
        for(int i=0;i<inorder.size();++i)
        {
            in_map[inorder[i]] = i;
        }

        return buildTree(preorder, inorder, 0, inorder.size()-1);
    }
};
