class Solution {
public:
 
    vector<vector<int>> findTargetPair(vector<int>& nums, int target, int start)
    {
        vector<vector<int>> ret;
        int left = start+1;
        int right = nums.size()-1;
        if(nums[left] > target)
            return {};
        while(left<right)
        {
            int sum = nums[left] + nums[right];
            if(sum > target)
            {
                --right;
            }
            else if(sum < target)
            {
                ++left;
            }
            else if (sum == target)
            {
                ret.push_back({nums[start], nums[left], nums[right]});
                ranges::sort(ret.back());
                ++left;
                --right;
                while(left<right && nums[left] == nums[left-1])
                {
                    ++left;
                }
            }
        }
        return ret;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        ranges::sort(nums);
        for(int i=0;i<nums.size();++i)
        {
            if (nums[i] > 0) break; // all remaining numbers are positive
            if (i>0 && nums[i] == nums[i-1]) continue; // skip duplicates
            
            int target = -nums[i];
            auto triplets = findTargetPair(nums, target, i);
            for(const auto& triplet : triplets)
            {
                ret.push_back(triplet);
            }
        }

        return ret;
    }
};
