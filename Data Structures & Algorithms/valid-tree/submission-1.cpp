class Solution {
public:
    bool validTree(int n, vector<vector<int>>& pairs) {
        vector<vector<int>> edges(n);
        for(const auto& pair : pairs)
        {
            int a = pair[0] < pair[1] ? pair[0] : pair[1];
            int b = pair[0] < pair[1] ? pair[1] : pair[0];
            edges[a].push_back(b);
            edges[b].push_back(a);
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
