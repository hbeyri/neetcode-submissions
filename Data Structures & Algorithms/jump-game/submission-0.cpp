class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumps = 1;
        int i = 0;
        for(int v : nums)
        {
            --jumps;
            jumps = max(jumps, v);
            if(jumps==0 && i<nums.size()-1)
                return false;
            ++i;
        }
        return true;
    }
};
