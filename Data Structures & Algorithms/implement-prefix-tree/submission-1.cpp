struct TrieNode
{
    std::array<TrieNode*, 26> children = {};
    bool endOfWord = false;
};

class PrefixTree {
private:
    TrieNode root;

public:
    PrefixTree() = default;
    
    void insert(string word) 
    {
        TrieNode* node = &root;
        for(char c : word)
        {
            if(!node->children[c-'a'])
                node->children[c-'a'] = new TrieNode;
            node = node->children[c-'a'];
        }
        node->endOfWord = true;
    }
    
    bool search(string word) const 
    {
        const TrieNode* node = find(word);
        return node && node->endOfWord;
    }
    
    bool startsWith(string prefix) const 
    {
        const TrieNode* node = find(prefix);
        return node;
    }
private:
    const TrieNode* find(string s) const
    {
        const TrieNode* node = &root;
        for(char c : s)
        {
            if(!node->children[c-'a'])
                return nullptr;
            node = node->children[c-'a'];
        }
        return node;
    }
};
