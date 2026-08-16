class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {}; // 1-based index
        int ret = 0;
        int tail = 0;
        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            if(m[c] != 0)
            {
                // if index stored
                tail = max(m[c], tail);
            }
            int len = i - tail + 1;
            ret = max(ret, len);
            m[c] = i+1;
        }

        return ret;
    }
};
