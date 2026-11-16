class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(const auto& str : strs)
        {
            int count[26] = {0};
            for(char c : str)
            {
                ++count[c-'a'];
            }
            string key;
            for(int i=0;i<26;++i)
            {
                if(count[i] > 0)
                {
                    key.push_back('a' + i);
                    key += to_string(count[i]);
                }
            }
            m[key].push_back(str);
        }

        vector<vector<string>> ret;
        for(const auto& e : m)
        {
            ret.push_back(e.second);
        }
        return ret;
    }
};
