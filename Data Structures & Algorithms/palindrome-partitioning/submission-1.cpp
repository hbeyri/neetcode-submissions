class Solution {
public:
    const int PAL = 1;
    const int NOT_PAL = 2;

    vector<vector<string>> ret;
    vector<string> cur;
    int m[20][20] = {};
    int n;

    bool isPalindrome(const string& s, int start, int end)
    {
        if(start >= end)
            return true;
        else if(m[start][end] != 0)
            return m[start][end] == PAL;
        else if(s[start] == s[end] 
            && isPalindrome(s, start+1, end-1))
        {
            m[start][end] = PAL;
            return true;
        }
        m[start][end] = NOT_PAL;
        return false;
    }

    void partition(const string& s, int start)
    {
        if(start>=n && cur.size() > 0)
            ret.push_back(cur);

        for(int j=start;j<n;++j)
        {
            if(isPalindrome(s, start, j))
            {
                cur.push_back(s.substr(start, j-start+1));
                partition(s, j+1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        partition(s, 0);
        return ret;
    }
};
