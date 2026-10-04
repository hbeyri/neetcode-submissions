class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do
        {
            int next_slow = nums[slow];
            int next_fast = nums[nums[fast]];
            slow = next_slow;
            fast = next_fast;
        }
        while(slow!=fast);
        fast = 0;
        while(nums[slow] != nums[fast])
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return nums[slow];
    }
};
