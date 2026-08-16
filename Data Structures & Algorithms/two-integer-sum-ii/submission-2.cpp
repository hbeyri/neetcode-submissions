class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(true)
        {
            int sum = nums[left] + nums[right];
            if(sum > target)
                --right;
            else if(sum < target)
                ++left;
            else
                return {left+1, right+1};
        }

        return {};
    }
};
