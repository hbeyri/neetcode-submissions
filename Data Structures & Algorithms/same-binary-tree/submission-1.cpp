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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({a, b});
        while(!q.empty())
        {
            auto [c,d] = q.front();
            q.pop();
            if(((c==nullptr || d==nullptr) && c!=d)
                || (c && d && c->val != d->val))
                return false;
            if(c && d)
            {
                q.push({c->left, d->left});
                q.push({c->right, d->right});
            }
        }
        return true;
    }
};
