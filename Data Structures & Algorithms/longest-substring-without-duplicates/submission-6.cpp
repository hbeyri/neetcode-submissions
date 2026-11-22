class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int start = 0;
        unordered_map<char, int> m;
        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            if(m[c] != 0)
            {
                int prev_start = start;
                start = m[c];
                for(int j=prev_start;j<=m[c]-1;++j)
                {
                    m[s[j]] = 0;
                }
            }

            m[c] = i+1;
            ret = max(ret, i - start + 1);
        }

        return ret;
    }
};
