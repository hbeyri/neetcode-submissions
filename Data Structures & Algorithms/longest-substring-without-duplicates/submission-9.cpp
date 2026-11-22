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
                start = max(m[c], start);
            }

            m[c] = i+1;
            ret = max(ret, i - start + 1);
        }

        return ret;
    }
};
