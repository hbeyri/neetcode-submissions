class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int prefix = 1;
        int suffix = 1;
        for(int i=1;i<nums.size();++i)
        {
            prefix *= nums[i-1];
            ret[i] = prefix;
        }
        for(int i=nums.size()-2;i>=0;--i)
        {
            suffix *= nums[i+1];
            ret[i] *= suffix;
        }
        
        return ret;
    }
};
