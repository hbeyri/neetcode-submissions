class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i=0;i<32;++i)
        {
            bool bit_set = n & (1<<i);
            ret |= bit_set? (1 << (31-i)) : 0;
        }
        return ret;
    }
};
