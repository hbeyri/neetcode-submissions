class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {}; // 1-based index
        int ret = 0;
        int len = 0;
        int tail = 0;
        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            if(m[c] == 0)
            {
                ++len;
                ret = max(ret, len);
            }
            else
            {
                // clear everything between tail_index and
                // m[c]
                int new_tail = m[c];
                for(int j=tail;j<m[c];++j)
                    m[s[j]] = 0;
                tail = new_tail;
                len = i - tail + 1;
            }
            // cout<<c<<" "<<len<<endl;
            m[c] = i+1;
        }

        return ret;
    }
};
