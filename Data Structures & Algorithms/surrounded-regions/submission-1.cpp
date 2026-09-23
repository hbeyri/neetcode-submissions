class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;
        for(int i=0;i<rows;++i)
        {
            if(board[i][0]=='O')
                q.push({i, 0});
            if(board[i][cols-1]=='O')
                q.push({i, cols-1});
        }

        for(int j=0;j<cols;++j)
        {
            if(board[0][j]=='O')
                q.push({0, j});
            if(board[rows-1][j]=='O')
                q.push({rows-1, j});
        }

        while(!q.empty())
        {
            auto[i, j] = q.front();
            q.pop();
            board[i][j] = 'E';
            for(const auto& dir : dirs)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if(new_i < 0 || new_j < 0 || new_i>=rows || new_j >= cols)
                    continue;
                char& c = board[new_i][new_j];
                if(c == 'X' || c=='E')
                    continue;
                c = 'E';
                q.push({new_i, new_j});
            }
        }

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                char& c = board[i][j];
                if(c=='O')
                    c='X';
                else if(c=='E')
                    c='O';
            }
            cout<<endl;
        }
    }
};
