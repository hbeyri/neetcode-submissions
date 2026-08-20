class Solution {
public:
    pair<int, int> dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        int dist = 0;
        while(!q.empty())
        {
            int n = q.size();
            ++dist;
            for(int index=0;index<n;++index)
            {
                auto[i, j] = q.front();
                q.pop();
                for(const auto&[diri, dirj] : dirs)
                {
                    int ni = i + diri;
                    int nj = j + dirj;
                    if(ni<0 || nj<0 || ni>=rows || nj>=cols
                        || grid[ni][nj] <= dist)
                        continue;
                    
                    grid[ni][nj] = dist;
                    q.push({ni, nj});
                }
            }
        }
    }
};
