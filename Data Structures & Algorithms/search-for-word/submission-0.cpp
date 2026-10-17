class Solution {
public:
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int rows, cols;

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int wi)
    {
        if(word[wi] == board[i][j])
        {
            if(wi == word.size() - 1)
                return true;

            board[i][j] = '_';

            for(int dir=0;dir<4;++dir)
            {
                int nexti = i + DIRS[dir][0];
                int nextj = j + DIRS[dir][1];
                if(nexti<0 || nextj<0 
                    || nexti>=rows||nextj>=cols
                    || board[i][j] != '_')
                    continue;

                if(dfs(board, nexti, nextj, word, wi+1))
                    return true;
            }

            board[i][j] = word[wi];
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(board[i][j] == word[0])
                    if(dfs(board, i, j, word, 0))
                        return true;
            }
        }

        return false;
    }
};
