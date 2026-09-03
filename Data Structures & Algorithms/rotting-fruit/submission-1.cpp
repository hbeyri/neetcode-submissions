class Solution {
public:
    pair<int, int> dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        bool all_zeroes = true;
        queue<pair<int, int>> q;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }

                if(grid[i][j]!=0)
                {
                    all_zeroes = false;
                }
            }
        }

        if(all_zeroes)
            return 0;

        int depth = 0;
        while(!q.empty())
        {
            ++depth;
            int q_size = q.size();
            for(int k=0;k<q_size;++k)
            {
                auto[i, j] = q.front();
                cout<<depth<<" "<<i<<" "<<j<<endl;
                q.pop();
                for(auto dir : dirs)
                {
                    int ni = i + dir.first;
                    int nj = j + dir.second;

                    if(ni<0 || nj<0 || ni>=rows || nj>=cols)
                        continue;

                    if(grid[ni][nj] == 1)
                    {
                        q.push({ni, nj});
                        grid[ni][nj] = -depth;
                    }
                }
            }
        }

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return depth-1;
    }
};
