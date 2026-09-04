class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0;
        int freq[256] = {};
        int tail = 0;
        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            ++freq[c];
            int maxfreq = *max_element(begin(freq), end(freq));
            int len = i-tail+1;
            while((maxfreq+k) < len)
            {
                --freq[s[tail]];
                ++tail;
                maxfreq = *max_element(begin(freq), end(freq));
                len = i-tail+1;
            }
            ret = max(ret, len);
        }

        return ret;
    }
};
