class Solution {
public:
    unordered_map<int, vector<vector<string>>> m;

    bool isPalindrome(const string& s, int left, int right) const
    {
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            ++left;--right;
        }
        return true;
    }

    vector<vector<string>> recurse(const string& s, int end)
    {
        if(end < 0)
            return {{}};
        
        if(m.contains(end))
            return m[end];

        vector<vector<string>> ret;
        int start = end;
        while(start >= 0)
        {
            if(isPalindrome(s, start, end))
            {
                vector<vector<string>> recurse_ret = recurse(s, start-1);
                for(const auto& v : recurse_ret)
                {
                    ret.push_back(v);
                    ret.back().push_back(s.substr(start, end-start+1));
                }
            }
            --start;
        }

        m[end] = ret;
        return ret;
    }

    vector<vector<string>> partition(string s) {
        return recurse(s, s.size()-1);
    }
};
