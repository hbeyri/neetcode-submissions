class TreeNode
{
public:
    array<TreeNode*, 26> children = {};
    bool endOfWord = false;
};

class PrefixTree {
public:
    TreeNode root;

    PrefixTree() {
        
    }
    
    void insert(string word) {
        TreeNode* node = &root;
        for(char c : word)
        {
            if(!node->children[c-'a'])
            {
                node->children[c-'a'] = new TreeNode();
            }
            node = node->children[c-'a'];
        }
        node->endOfWord = true;
    }
    
    bool search(string word) {
        TreeNode* node = &root;
        for(char c : word)
        {
            node = node->children[c-'a'];
            if(!node)
                return false;
        }

        return node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* node = &root;
        for(char c : prefix)
        {
            node = node->children[c-'a'];
            if(!node)
                return false;
        }

        return true;
    }
};
