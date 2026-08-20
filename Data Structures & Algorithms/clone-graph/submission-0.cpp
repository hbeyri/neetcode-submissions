/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> m;

public:
    Node* cloneGraph(Node* root) {
        if(!root)
            return nullptr;
        queue<pair<Node*, Node*>> q;
        Node* ret = new Node(root->val);
        q.push({root, ret});
        m.insert({root, ret});
        while(!q.empty())
        {
            auto[node, clone] = q.front();
            q.pop();
            for(auto neighbor : node->neighbors)
            {
                if(!m.contains(neighbor))
                {
                    Node* neighbor_clone = new Node(neighbor->val);
                    m.insert({neighbor, neighbor_clone});
                    q.push({neighbor, neighbor_clone});
                }
                clone->neighbors.push_back(m[neighbor]);
            }
        }

        return ret;
    }
};
