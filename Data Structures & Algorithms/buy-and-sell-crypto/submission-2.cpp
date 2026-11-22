class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int ret = 0;
        for(int i=1;i<prices.size();++i)
        {
            int price = prices[i];
            ret = max(ret, price - minprice);
            minprice = min(minprice, price);
        }
        return ret;
    }
};
