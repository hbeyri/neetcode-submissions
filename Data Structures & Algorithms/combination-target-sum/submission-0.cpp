class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void recurse(const vector<int>& nums, int start, int target)
    {
        if(target == 0)
        {
            ret.push_back(cur);
            return;
        }

        for(int i=start;i<nums.size();++i)
        {
            if(nums[i] > target)
                break;

            cur.push_back(nums[i]);
            recurse(nums, i, target-nums[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        recurse(nums, 0, target);

        return ret;
    }
};
