class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; // minheap
        unordered_set<int> visited;
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
            
            if(visited.contains(node))
                continue;

            ret = node_t;
            visited.insert(node);

            for(const auto& dest : edges[node])
            {
                auto[next, next_t] = dest;
                if(!visited.contains(next))
                {
                    q.push({node_t + next_t, next});
                }
            }
        }

        if(visited.size() != n)
            return -1;

        return ret;
    }
};
