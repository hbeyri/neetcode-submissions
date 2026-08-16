class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        ret.resize(n);
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i=1;i<n;++i)
        {
            left[i] = left[i-1] * nums[i]; 
        }

        for(int j=n-2;j>=0;--j)
        {
            right[j] = right[j+1] * nums[j];
        }

        ret[0] = right[1];
        ret[n-1] = left[n-2];
        for(int i=1;i<n-1;++i)
        {
            ret[i] = left[i-1]*right[i+1];
        }

        return ret;
    }
};
