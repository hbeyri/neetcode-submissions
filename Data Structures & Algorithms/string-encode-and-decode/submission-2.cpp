class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for(const auto& s : strs)
        {
            int len = s.size();
            ret += to_string(len) + "#";
            ret += s;
        }

        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        for(int i = 0;i<s.size();++i)
        {
            string lenstr;
            for(;i<s.size();++i)
            {
                char c = s[i];
                if(c!='#')
                    lenstr += c;
                else
                    break;
            }
            ++i;
            int len = stoi(lenstr);
            ret.push_back(s.substr(i, len));
            i = i + len - 1;
        }

        return ret;
    }
};
