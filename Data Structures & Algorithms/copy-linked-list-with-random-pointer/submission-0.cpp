/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;

    Node* createOrGetClone(Node* node)
    {
        if(!node) return nullptr;

        auto iter = m.find(node);
        if(iter != m.end())
        {
            return iter->second;
        }
        return m.insert({node, new Node(node->val)}).first->second;
    }

    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* cur = head;
        Node* clone = createOrGetClone(cur);
        clone->random = createOrGetClone(cur->random);
        clone->next = createOrGetClone(cur->next);

        while(cur->next)
        {
            clone = clone->next;
            cur = cur->next;
            clone->random = createOrGetClone(cur->random);
            clone->next = createOrGetClone(cur->next);
        }

        return m[head];
    }
};
