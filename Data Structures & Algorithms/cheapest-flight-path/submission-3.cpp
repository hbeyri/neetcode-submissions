class Solution {
public:
    // edges[u] = list of {price, next} for every flight leaving airport u
    unordered_map<int, vector<array<int, 2>>> edges;

    // memo[node][k] = cheapest cost from node to dst using at most k flights
    // -2 = not computed yet, -1 = impossible
    vector<vector<int>> memo;

    // Returns the cheapest cost from src to dst using at most k flights, or -1 if impossible.
    int dfs(int src, int dst, int k)
    {
        // Reached the destination: no more cost to add
        if(src == dst)
            return 0;

        // Out of flights before reaching dst
        if(k==0)
            return -1;

        // Already solved this (airport, flights left) state
        if(memo[src][k] != -2)
            return memo[src][k];

        // Try every outgoing flight and keep the cheapest way to finish from there
        int min_price = -1;
        for(const auto& [price, next] : edges[src])
        {
            int sub = dfs(next, dst, k-1);
            if(sub != -1 && (min_price == -1 || (price + sub) < min_price))
                min_price = price + sub;
        }

        // Cache the result (including -1) so this state is never recomputed
        return memo[src][k] = min_price;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(const auto& flight : flights)
        {
            // price first, then dest second
            int dest = flight[1];
            int price = flight[2];
            edges[flight[0]].push_back({price, dest});
        }

        // k stops = at most k+1 flights, so the flights-left index goes up to k+1
        memo = vector<vector<int>>(n, vector<int>(k+2, -2));
        return dfs(src, dst, k+1);
    }
};