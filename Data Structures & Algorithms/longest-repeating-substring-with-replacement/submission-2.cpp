class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0;
        int freq[256] = {};
        int maxfreq = 0;;
        int tail = 0;
        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            ++freq[c];
            maxfreq = max(maxfreq, freq[c]);
            while((i - tail + 1) - maxfreq > k)
            {
                --freq[s[tail]];
                ++tail;
                // we intentionally do not update maxfreq here, 
                // because while it's not really accurate, 
                // stale maxfreq doesn't actually affect correctness
                // because it cannot make the algorithm record length
                // larger than the one that was achievable when
                // maxfreq was accurate
            }
            ret = max(ret, i-tail+1);
        }

        return ret;
    }
};
