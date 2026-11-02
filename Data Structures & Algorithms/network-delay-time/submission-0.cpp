class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<int> q;
        unordered_map<int, int> visited;
        vector<vector<pair<int, int>>> edges(n+1);
        for(const auto& time : times)
        {
            edges[time[0]].push_back({time[1], time[2]});
        }

        q.push(k);
        visited[k] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            int cur_time = visited[node];

            for(const auto& dest : edges[node])
            {
                auto[next, t] = dest;
                if(next == k)
                    continue;
                else if(!visited.contains(next) || (visited[next] > cur_time + t))
                {
                    visited[next] = cur_time+t;
                    q.push(next);
                }
            }
        }

        if(visited.size() != n)
            return -1;

        int max_t = 0;
        for(const auto& p : visited)
            max_t = max(p.second, max_t);

        return max_t;
    }
};
