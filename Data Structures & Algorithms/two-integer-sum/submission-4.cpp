class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m[nums[0]] = 0;
        for(int i=1;i<nums.size();++i)
        {
            int v = nums[i];
            auto find = m.find(target - v);
            if(find != m.end())
            {
                return {m[target-v], i};
            }
            m[v] = i;
        }
        return {};
    }
};
