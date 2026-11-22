class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        unordered_map<char, int> m;
        int max_freq = 0;
        int ret = 0;

        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            ++m[c];
            max_freq = max(max_freq, m[c]);

            while((i - start + 1) - max_freq > k)
            {
                --m[s[start]];
                ++start;
            }

            ret = max(ret, i-start+1);
        }

        return ret;
    }
};
