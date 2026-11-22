class Solution {
public:
    unordered_map<char, int> s;
    unordered_map<char, int> seen;
    
    bool isComplete()
    {
        for(const auto&[key, value] : s)
        {
            if(s[key] <= 0)
                continue;

            if(seen[key] < value)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string str, string t) {
        int left = 0;
        for(char c : t)
            ++s[c];

        string ret;
        for(int i=0;i<str.size();++i)
        {
            char c = str[i];
            
            if(!ret.empty())
            {
                // no need to have sliding window bigger
                // than the current ret size
                left = i-(ret.size()-1);
                if(seen[str[left-1]] > 0)
                   --seen[str[left-1]]; 
            }
            if(s[c] > 0)
            {
                ++seen[c];
                if(isComplete())
                {
                    while((left < i) 
                        && (s[str[left]] == 0
                            || seen[str[left]] > s[str[left]])
                    )
                    {
                        if(seen[str[left]] > 0)
                            --seen[str[left]];
                        ++left;
                    }
                    int sublen = i - left + 1;
                    if(ret.empty() || ret.size() > sublen)
                        ret = str.substr(left, sublen);
                }
            }
        }

        return ret;
    }
};
