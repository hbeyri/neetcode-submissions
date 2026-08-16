class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> m = {};
        for(char c : s)
        {
            ++m[c-'a'];
        }
        for(char c : t)
        {
            --m[c-'a'];
        }
        for(int v : m)
        {
            if(v!=0)
                return false;
        }
        return true;
    }
};
