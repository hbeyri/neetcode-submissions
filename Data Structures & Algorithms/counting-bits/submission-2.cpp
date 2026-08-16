class Solution {
public:
    // slightly less optimal
    // vector<int> countBits(int n) {
    //     if(n==0) return {0};
    //     if(n==1) return {0,1};
    //     vector<int> ret = {0, 1};
    //     int next_pow2 = 4;
    //     int tail = 0;
    //     for(int i=2;i<=n;++i)
    //     {
    //         if(i==next_pow2)
    //         {
    //             tail = 0;
    //             next_pow2*=2;
    //         }
    //         ret.push_back(ret[tail]+1);
    //         ++tail;
    //     }

    //     return ret;
    // }

    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
