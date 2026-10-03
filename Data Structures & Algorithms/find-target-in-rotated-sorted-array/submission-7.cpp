class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right) 
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;

            // right side is normal sorted ascending order
            if(nums[mid] < nums[right])
            {
                if(target<nums[mid] || target>nums[right])
                    right = mid-1;
                else
                    left = mid+1;
            }
            // left side is normal sorted ascending order
            else
            {
                if(target>nums[mid] || target<nums[left])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }

        return -1;
    }
};
