class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = 0;
        int b = 0;
        for(int i=2;i<=n;++i)
        {
            int c = min(a + cost[i-2], b + cost[i-1]);
            a = b;
            b = c;
        }
        return b;
    }
};
