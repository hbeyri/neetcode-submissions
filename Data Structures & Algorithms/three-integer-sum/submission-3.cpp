class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        set<array<int, 2>> s;
        unordered_map<int, int> m;
        for(int v : nums)
            ++m[v];

        for(int i=0;i<nums.size()-1;++i)
        {
            --m[nums[i]];
            for(int j=i+1;j<nums.size();++j)
            {
                int sum = nums[i] + nums[j];
                --m[nums[j]];
                int min_el = min({nums[i], nums[j], -sum});
                int max_el = max({nums[i], nums[j], -sum});
                if(m[-sum] > 0 && !s.contains({min_el, max_el}))
                {
                    ret.push_back({nums[i], nums[j], -sum});
                    s.insert({min_el, max_el});
                }
                ++m[nums[j]];
            }
            ++m[nums[i]];
        }

        return ret;
    }
};
