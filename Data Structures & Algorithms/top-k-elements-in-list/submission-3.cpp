class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,  int> m;
        for(int num : nums)
        {
            ++m[num];
        }

        vector<vector<int>> buckets;
        buckets.resize(nums.size()+1);
        for(const auto& [key, value] : m)
        {
            buckets[value].push_back(key);
        }

        vector<int> ret;
        for(int i = buckets.size()-1; i>=0; --i)
        {
            if(buckets[i].size() > 0)
            {
                for(int v : buckets[i])
                {
                    ret.push_back(v);
                    if(ret.size() == k)
                        return ret;
                }
            }
        }

        return ret;
    }
};
