class Solution {
public:

    string s;
    vector<string> ret;

    void recurse(int n, int open, int close)
    {
        if(s.size()==n*2)
            ret.push_back(s);
        else
        {
            if(open < n)
            {
                s.push_back('(');
                recurse(n, open+1, close);
                s.pop_back();
            }
            if(close<open)
            {
                s.push_back(')');
                recurse(n, open, close+1);
                s.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        s = "";
        recurse(n, 0, 0);
        return ret;
    }
};
