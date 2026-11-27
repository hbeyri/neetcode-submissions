class Solution {
public:
    int rows;
    int cols;

    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool recurse(vector<vector<char>>& board, const string& word, int wstart, int i, int j) 
    {
        if(word[wstart] != board[i][j])
            return false;
        if(wstart == word.size()-1)
            return true;
        
        char ori = board[i][j];
        board[i][j] = ' ';
        
        for(int k=0;k<4;++k)
        {
            int i_next = i + dirs[k][0];
            int j_next = j + dirs[k][1];
            if(i_next < 0 || i_next >= rows || j_next<0 || j_next>=cols)
                continue;

            if(recurse(board, word, wstart+1, i_next, j_next))
                return true;
        }

        board[i][j] = ori;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
                if(word[0] == board[i][j] && recurse(board, word, 0, i, j))
                    return true;

        return false;
    }
};
