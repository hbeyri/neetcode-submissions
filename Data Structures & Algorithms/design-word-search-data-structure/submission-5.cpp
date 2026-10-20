class TreeNode
{
public:
    array<TreeNode*, 26> children;
    bool endOfWord = false;
};

class WordDictionary {
public:
    TreeNode root{};
    
    void addWord(string word) {
        TreeNode* node = &root;

        for(char c : word)
        {
            if(!node->children[c-'a'])
            {
                node->children[c-'a'] = new TreeNode{};
            }
            node = node->children[c-'a'];
        }

        node->endOfWord = true;
    }
    
    bool Search(TreeNode* node, const string& word, int wordstart)
    {
        for(int wi=wordstart;wi<word.size();++wi)
        {
            char c = word[wi];
            if(c!='.' && !node->children[c-'a'])
                return false;
            else if(c=='.')
            {
                // char test = 'a';
                for(TreeNode* child : node->children)
                {
                    // cout<<"recurse "<<test<<endl;
                    if(child && Search(child, word, wi+1))
                        return true;
                    // ++test;
                }
                return false;
            }
            else
            {
                node = node->children[c-'a'];
            }
        }
        // cout<<"aaaa "<<node->endOfWord<<" "<<endl;
        return node->endOfWord;
    }

    bool search(string word) {
        return Search(&root, word, 0);
    }
};
