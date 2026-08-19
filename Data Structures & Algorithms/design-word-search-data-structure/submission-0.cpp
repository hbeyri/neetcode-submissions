struct TrieNode
{
    std::array<TrieNode*, 26> children = {};
    bool isEndOfWord = false;
};

class WordDictionary {
    TrieNode root;

public:
    WordDictionary() = default;
    
    void addWord(const string& word) {
        TrieNode* node = &root;
        for(char c : word)
        {
            if(!node->children[c-'a'])
                node->children[c-'a'] = new TrieNode;
            node = node->children[c-'a'];
        }
        node->isEndOfWord = true;
    }
    
    bool search(const TrieNode* node, const string& word) const
    {
        for(int i=0;i<word.size();++i)
        {
            char c = word[i];
            if(c=='.')
            {
                if(i < word.size()-1)
                {
                    for(TrieNode* child : node->children)
                    {
                        if(child && search(child, word.substr(i+1)))
                            return true;
                    }
                    return false;
                }
                else
                {
                    for(TrieNode* child : node->children)
                    {
                        if(child && child->isEndOfWord)
                            return true;
                    }
                    return false;
                }
            }
            else
            {
                if(!node->children[c-'a'])
                    return false;
                node = node->children[c-'a'];
            }
        }
        return node && node->isEndOfWord;
    }

    bool search(const string& word) const {
        return search(&root, word);
    }
};
