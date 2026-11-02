class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; // minheap
        vector<int> visited(n+1);
        vector<vector<pair<int, int>>> edges(n+1);
        for(const auto& time : times)
        {
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        int ret = 0;
        q.push({0, k});
        while(!q.empty())
        {
            auto[node_t, node] = q.top();
            q.pop();
            
            if(visited[node])
                continue;

            ret = node_t;
            visited[node] = true;

            for(const auto& dest : edges[node])
            {
                auto[next, next_t] = dest;
                if(!visited[next])
                {
                    q.push({node_t + next_t, next});
                }
            }
        }

        for(int i=1;i<=n;++i)
            if(!visited[i])
                return -1;

        return ret;
    }
};
