class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right)
        {
            int mid = (left + right) / 2;
            cout<<left<<" "<<right<<endl;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] < nums[right])
            {
                // right side is sorted

                if(target>nums[mid] && target<=nums[right])
                {
                    left = mid+1;
                    continue;
                }
                right = mid-1;
            }
            else
            {
                // left side is sorted
                if(target>=nums[left] && target<nums[mid])
                {
                    right = mid-1;
                    continue;
                }
                left = mid+1;
            }
        }

        return -1;
    }
};
