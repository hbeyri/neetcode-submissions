class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> neighbors;
        for(const auto& edge : edges)
        {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        vector<uint8_t> visited(n);
        for(int i=0;i<n;++i)
        {
            if(visited[i])
                continue;

            ++count;
            stack<int> st;
            st.push(i);
            visited[i] = true;
            while(!st.empty())
            {
                int node = st.top();
                st.pop();

                for(int next : neighbors[node])
                {
                    if(!visited[next])
                    {
                        st.push(next);
                        visited[next] = true;
                    }
                }
            }
        }

        return count;
    }
};
