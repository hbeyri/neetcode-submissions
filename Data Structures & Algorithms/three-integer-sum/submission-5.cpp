class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_map<int, int> m;
        sort(nums.begin(), nums.end());
        for(int v : nums)
            ++m[v];

        for(int i=0;i<nums.size()-1;++i)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue; // skip repeated first element cause we've already seen it

            --m[nums[i]];
            for(int j=i+1;j<nums.size();++j)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                    continue; // skip repeated first element cause we've already seen it

                int sum = nums[i] + nums[j];

                if(-sum < nums[j])
                    continue; // keep a<=b<=c
                
                --m[nums[j]];
                if(m[-sum] > 0)
                {
                    ret.push_back({nums[i], nums[j], -sum});
                }
                ++m[nums[j]];
            }
            ++m[nums[i]];
        }

        return ret;
    }
};
