class Solution {
public:
    bool validTree(int n, vector<vector<int>>& pairs) {
        if (pairs.size() > n - 1) {
            return false;
        }
        
        vector<vector<int>> edges(n);
        for(const auto& pair : pairs)
        {
            edges[pair[0]].push_back(pair[1]);
            edges[pair[1]].push_back(pair[0]);
        }

        queue<pair<int, int>> q;
        vector<bool> m(n);
        q.push({0, 0});
        m[0] = true;
        while(!q.empty())
        {
            auto[from, n] = q.front();
            q.pop();

            for(int next : edges[n])
            {
                if(next == from)
                    continue;
                if(m[next])
                    return false;
                q.push({n, next});
                m[next] = true;
            }
        }

        return !ranges::contains(m, false);
    }
};
