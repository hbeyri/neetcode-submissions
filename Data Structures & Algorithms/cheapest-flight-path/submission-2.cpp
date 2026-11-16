class Solution {
public:
    unordered_map<int, vector<array<int, 2>>> edges;
    vector<uint8_t> visited;
    int cur_price = 0;
    int min_price = -1;

    void dfs(int src, int dst, int k)
    {
        if(src == dst)
        {
            if(min_price == -1)
                min_price = cur_price;
            else
                min_price = min(min_price, cur_price);
            return;
        }

        if(k==0)
            return;

        // cout<<"k = "<<k<<endl;
        // cout<<"test "<<src<<" "<<edges[src].size()<<endl;
        for(const auto& [price, next] : edges[src])
        {
            // cout<<next<<" "<<dist<<endl;
            if(!visited[next] && (min_price == -1 || ((cur_price + price) < min_price)))
            {
                visited[next] = true;
                cur_price += price;
                dfs(next, dst, k-1);
                cur_price -= price;
                visited[next] = false;
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(const auto& flight : flights)
        {
            // price first, then dest second
            int dest = flight[1];
            int price = flight[2];
            edges[flight[0]].push_back({price, dest});
        }
        for(auto& edge : edges)
        {
            sort(edge.second.begin(), edge.second.end());
        }
        visited = vector<uint8_t>(n);
        dfs(src, dst, k+1);
        return min_price;
    }
};
