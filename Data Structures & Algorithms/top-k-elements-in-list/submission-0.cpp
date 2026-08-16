class Solution {
public:
    struct Data
    {
        int val;
        int freq;
    };

    static bool Compare(const Data& a, const Data& b)
    {
        return a.freq < b.freq;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<Data, vector<Data>, decltype(&Compare)> pq(&Compare);
        std::unordered_map<int, int> m;
        m.reserve(nums.size());
        for(int v : nums)
        {
            ++m[v];
        }
        for(const auto& kv : m)
        {
            pq.push({kv.first, kv.second});
        }
        vector<int> ret;
        ret.reserve(k);
        for(int i=0;i<k;++i)
        {
            ret.push_back(pq.top().val);
            pq.pop();
        }
        return ret;
    }
};
