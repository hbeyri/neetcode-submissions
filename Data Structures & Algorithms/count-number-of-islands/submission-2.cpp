class Solution {
public:
    vector<char> visited;
    int rows;
    int cols;

    bool isVisited(int i, int j, const vector<vector<char>>& grid) const
    {
        if(i<0 || j<0 || i>=rows || j>=cols)
            return true;
        return grid[i][j]=='0' || visited[i*cols+j];
    }

    void visit(int i, int j, queue<pair<int, int>>& q)
    {
        q.push({i, j});
        visited[i*cols+j] = true;
    }

    void bfs(int i, int j, const vector<vector<char>>& grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty())
        {
            auto[r, c] = q.front();
            q.pop();
            if(!isVisited(r, c+1, grid))
                visit(r, c+1, q);
            if(!isVisited(r+1, c, grid))
                visit(r+1, c, q);
            if(!isVisited(r, c-1, grid))
                visit(r, c-1, q);
            if(!isVisited(r-1, c, grid))
                visit(r-1, c, q);
        }
    }

    int numIslands(const vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited = vector<char>(rows*cols, false);
        int ret = 0;

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                int v = grid[i][j];
                if(isVisited(i, j, grid) || v == '0')
                    continue;
                
                // we found island
                ++ret;
                visited[i*cols+j] = true;
                bfs(i, j, grid);
            }
        }

        return ret;
    }
};
