class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int ret;
        while(left<right)
        {
            int mid = (right + left) / 2;
            if(nums[mid] <= nums[right])
                right = mid;
            else
                left = mid+1;
        }

        return nums[right];
    }
};
