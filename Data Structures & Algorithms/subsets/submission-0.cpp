class Solution {
public:
    void choose(vector<int>& v, const vector<int>& nums, int start, int k)
    {
        if(v.size() == k)
        {
            ret.push_back(v);
            return;
        }

        for(int i=start;i<nums.size();++i)
        {
            v.push_back(nums[i]);
            choose(v, nums, i+1, k);
            v.pop_back();
        }
    }

    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.push_back({});
        for(int i=1;i<=nums.size();++i)
        {
            vector<int> v;
            choose(v, nums, 0, i);
        }

        return ret;
    }
};
