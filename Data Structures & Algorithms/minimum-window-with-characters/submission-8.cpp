class Solution {
public:
    unordered_map<char, int> s;
    unordered_map<char, int> seen;

    string minWindow(string str, string t) {
        int left = 0;
        for(char c : t)
            ++s[c];

        int have = 0;
        int need = s.size();
        int retidx[2] = {-1, -1};
        string ret;
        for(int i=0;i<str.size();++i)
        {
            char c = str[i];
            ++seen[c];

            if(s[c] > 0 && s[c] == seen[c])
                ++have;

            while(have==need)
            {
                int sublen = i - left + 1;
                if(retidx[0] == -1 || (retidx[1] - retidx[0]+1) > sublen)
                {
                    retidx[0] = left;
                    retidx[1] = i;
                }

                // shrink
                --seen[str[left]];
                if(s[str[left]] > 0 && seen[str[left]]<s[str[left]])
                    --have;
                ++left;
            }
        }

        if(retidx[0] != -1)
        {
            ret = str.substr(retidx[0], retidx[1] - retidx[0] + 1);
        }

        return ret;
    }
};
