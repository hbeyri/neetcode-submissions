class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int ret = nums[0];

        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            ret = min(ret, nums[mid]);
            if(nums[left] < nums[right])
                return min(ret, nums[left]);
            else if(nums[left] <= nums[mid])
                left = mid+1;
            else
                right = mid-1;
        }
        return ret;
    }
};
