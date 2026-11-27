class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void recurse(vector<int>& nums, int target, int i)
    {
        if(i >= nums.size())
            return;
        
        if(nums[i] > target)
            return;
        else if(nums[i] == target)
        {
            cur.push_back(nums[i]);
            ret.push_back(cur);
            cur.pop_back();
        }
        else
        {
            cur.push_back(nums[i]);
            recurse(nums, target - nums[i], i);
            cur.pop_back();
            recurse(nums, target, i+1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        recurse(nums, target, 0);
        return ret;
    }
};
