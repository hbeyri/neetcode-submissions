class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int sum = 0;
        for(int v : nums)
        {
            sum += v;
            sum = max(sum, v);
            ret = max(ret, sum);
        }

        return ret;
    }
};
