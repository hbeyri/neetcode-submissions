class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n!=0)
        {
            ++ret;
            n = n & (n-1); // remove the LSB
        }
        return ret;
    }
};
