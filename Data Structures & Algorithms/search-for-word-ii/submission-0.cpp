class Trie
{
public:
    bool isEnd = false;
    array<Trie*, 26> children;
};

class Solution {
public:
    int rows;
    int cols;
    int dirs[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    vector<string> ret;
    string cur;

    void recurse(vector<vector<char>>& board, int i, int j, Trie* node)
    {
        if(i < 0 || j < 0 || i>=rows || j>=cols || board[i][j] == ' ' || !node)
            return;

        char ori = board[i][j];
        Trie* child = node->children[ori-'a'];
        if(!child)
            return;

        board[i][j] = ' ';
        cur.push_back(ori);
        if(child->isEnd)
        {
            child->isEnd = false;
            ret.push_back(cur);
        }

        for(auto[diri, dirj] : dirs)
        {
            int next_i = i + diri;
            int next_j = j + dirj;
            recurse(board, next_i, next_j, child);
        }

        cur.pop_back();
        board[i][j] = ori;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie root;
        rows = board.size();
        cols = board[0].size();
        for(const auto& word : words)
        {
            Trie* parent = &root;
            for(char c : word)
            {
                Trie* child = parent->children[c-'a'];
                if(!child)
                    child = new Trie();

                parent->children[c - 'a'] = child;
                parent = child;
            }
            parent->isEnd = true;
        }

        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
                recurse(board, i, j, &root);

        return ret;
    }
};
