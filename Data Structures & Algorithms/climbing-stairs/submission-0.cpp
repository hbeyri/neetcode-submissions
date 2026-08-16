class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int a = 1; // i-2
        int b = 2; // i-1
        int ret;
        for(int i=3;i<=n;++i)
        {
            ret = a + b;
            a = b;
            b = ret;
        }
        return ret;
    }
};
