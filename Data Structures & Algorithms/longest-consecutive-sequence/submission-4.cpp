class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ret = 0;
        for(int v : nums)
            s.insert(v);

        for(int v : s)
        {
            if(!s.contains(v-1))
            {
                int cur = 1;
                while(s.contains(v + cur))
                    ++cur;
                ret = max(ret, cur);
            }
        }
        return ret;
    }
};
