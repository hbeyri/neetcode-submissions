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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";

        string ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node)
                ret += to_string(node->val) + " ";
            else
                ret += "null ";

            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }

        }

        return ret;
    }

    int i=0;
    string processTok(const string& data)
    {
        string token;
        char c = data[i];
        while(c!=' ')
        {
            token += c;
            ++i;
            c = data[i];
        }
        ++i;

        return token;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;

        TreeNode* ret = nullptr;
        queue<TreeNode*> q;
        while(i<data.size())
        {
            if(!ret)
            {
                string token = processTok(data);
                int val = stoi(token);
                TreeNode* node = new TreeNode(val);
                ret = node;
                q.push(node);
                continue;
            }

            int q_size = q.size();
            for(int i=0;i<q_size;++i)
            {
                // cout<<"check"<<endl;
                TreeNode* parent = q.front();
                q.pop();

                TreeNode* child_left = nullptr;
                string token = processTok(data);            
                if(token != "null")
                    child_left = new TreeNode(stoi(token));

                TreeNode* child_right = nullptr;
                token = processTok(data);            
                if(token != "null")
                    child_right = new TreeNode(stoi(token));

                parent->left = child_left;
                parent->right = child_right;

                if(child_left)
                    q.push(child_left);
                if(child_right)
                    q.push(child_right);
            }
        }

        return ret;
    }
};
