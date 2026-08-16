class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int minp = prices[0];
        int maxp = prices[0];
        for(int i=1;i<prices.size();++i)
        {
            ret = max(ret, prices[i] - minp);
            minp = min(minp, prices[i]);
        }

        return ret;
    }
};
