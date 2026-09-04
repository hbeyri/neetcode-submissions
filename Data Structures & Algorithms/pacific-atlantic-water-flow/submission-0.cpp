class Solution {
public:
    const int ATLANTIC = -1;
    const int PACIFIC = -2;
    const int VISITED = -1;

    pair<int, int> dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> pacific = heights;
        vector<vector<int>> atlantic = heights;
        queue<tuple<int, int, int>> q;
        
        for(int j=0;j<cols;++j)
        {
            pacific[0][j] = VISITED;
            q.push({0, j, PACIFIC});
            atlantic[rows-1][j] = VISITED;
            q.push({rows-1, j, ATLANTIC});
        }

        for(int i=0;i<rows;++i)
        {
            pacific[i][0] = VISITED;
            q.push({i, 0, PACIFIC});
            atlantic[i][cols-1] = VISITED;
            q.push({i, cols-1, ATLANTIC});
        }

        while(!q.empty())
        {
            auto[i, j, type] = q.front();
            q.pop();

            for(const auto& dir : dirs)
            {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if(ni < 0 || nj < 0 || ni >= rows || nj >= cols)
                    continue;

                if(heights[ni][nj] >= heights[i][j])
                {
                    int* visited = nullptr;
                    if(type == ATLANTIC)
                    {
                        visited = &atlantic[ni][nj];
                    }
                    else
                    {
                        visited = &pacific[ni][nj];
                    }

                    if(*visited != VISITED)
                    {
                        q.push({ni, nj, type});
                        *visited = VISITED;
                    }
                }                
            }
        }

        vector<vector<int>> ret;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(pacific[i][j] == VISITED && atlantic[i][j] == VISITED)
                {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
};
