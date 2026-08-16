class Solution {
public:
    bool m[10];
    void reset()
    {
        ranges::fill(m, false);
    }

    bool checkBox(vector<vector<char>>& board, int box_i, int box_j)
    {
        int row_start = box_i*3;
        int row_end = row_start+3;
        int col_start = box_j*3;
        int col_end = col_start+3;
        reset();
        for(int i=row_start;i<row_end;++i)
        {
            for(int j=col_start;j<col_end;++j)
            {
                char v = board[i][j];
                if(v == '.')
                    continue;
                else if(m[v-'0'])
                    return false;

                m[v-'0']=true;
            }
        }
        return true;
    }

    bool checkStraight(vector<vector<char>>& board, bool row, int index)
    {
        int n = board.size();
        reset();
        for(int j=0;j<n;++j)
        {
            char v = row? board[index][j] : board[j][index];

            if(v=='.')
                continue;
            else if(m[v-'0'])
                return false;    

            m[v-'0'] = true;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0;i<n;++i)
        {
            if(!checkStraight(board, true, i)
                || !checkStraight(board, false, i))
                return false; 
        }

        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                if(!checkBox(board, i, j))
                    return false;
            }
        }

        return true;
    }
};
