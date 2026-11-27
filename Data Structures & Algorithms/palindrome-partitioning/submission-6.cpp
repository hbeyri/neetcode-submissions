class Solution {
public:
    vector<vector<char>> pal;
    vector<string> cur;
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        int n = s.size();
        pal.assign(n, vector<char>(n, false));

        // prebuild the palindrome table
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                pal[i][j] = s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]);

        dfs(s, 0);
        return std::move(res);
    }

    void dfs(const string& s, int start) 
    {
        if (start == (int)s.size()) 
        {
            res.push_back(cur);
            return;
        }
        for (int end = start; end < (int)s.size(); ++end) 
        {
            if (!pal[start][end]) 
                continue;
            cur.push_back(s.substr(start, end - start + 1));
            dfs(s, end + 1);
            cur.pop_back();
        }
    }
};