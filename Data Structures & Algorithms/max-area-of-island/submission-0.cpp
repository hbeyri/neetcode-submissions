class Solution {
public:
    int rows, cols;
    pair<int, int> dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int area(vector<vector<int>>& grid, int i, int j)
    {
        int ret = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty())
        {
            auto[r, c] = q.front();
            q.pop();
            ++ret;
            grid[r][c] = 0;
            for(const auto&[diri, dirj] : dirs)
            {
                int nr = r+diri;
                int nc = c+dirj;
                if(nr<0||nc<0||nr>=rows||nc>=cols
                    || grid[nr][nc] == 0)
                    continue;
                grid[nr][nc] = 0;
                q.push({nr, nc});
            }
        }
        return ret;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        rows = grid.size();
        cols = grid[0].size();

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j] == 1)
                {
                    ret = max(ret, area(grid, i, j));
                }
            }
        }

        return ret;
    }
};
