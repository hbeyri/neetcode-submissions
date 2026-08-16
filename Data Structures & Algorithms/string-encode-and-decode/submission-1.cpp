class Solution {
public:

    string addheader(const string& s)
    {
        int len = s.size();
        char lenc = (char)len;
        return string{} + lenc + s;
    }

    string encode(vector<string>& strs) {
        string ret;
        for(const auto& str : strs)
        {
            ret += addheader(str);
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i=0;
        int n = s.size();
        while(i<n)
        {
            int lenc = (unsigned char)s[i];
            ++i;
            ret.push_back(s.substr(i, lenc));
            i+=lenc;
        }

        return ret;
    }
};
