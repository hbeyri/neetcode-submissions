class Solution {
public:

    string getKey(const string& s)
    {
        array<int, 26> arr = {};
        for(char c:s)
            ++arr[c-'a'];
        string ret;
        ret.reserve(s.size());
        for(int i=0;i<arr.size();++i)
        {
            for(int j=0;j<arr[i];++j)
            {
                ret.push_back(i+'a');
            }
        }
        return ret;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(const string& s:strs)
        {
            m[getKey(s)].push_back(s);
        }

        vector<vector<string>> ret;
        ret.reserve(m.size());

        for(const auto& iter : m)
        {
            ret.push_back(iter.second);
        }

        return ret;
    }
};
