class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();++i)
        {
            int rem = target - nums[i];
            auto find_iter = lower_bound(nums.begin()+i+1, nums.end(), rem);
            if(find_iter != nums.end() && *find_iter == rem)
            {
                return {i+1, (int)distance(nums.begin(), find_iter) + 1};
            }
        }

        return {};
    }
};
