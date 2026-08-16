class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m.reserve(nums.size());

        for(int i=0;i<nums.size();++i)
        {
            m[nums[i]] = i;
        }

        for(int i=0;i<nums.size();++i)
        {
            auto iter = m.find(target - nums[i]);
            if(iter != m.end() && iter->second != i)
            {
                int j = iter->second;
                int a = i<j ? i : j;
                int b = i<j ? j : i;
                return {a, b};
            }
        }

        return {};
    }
};
