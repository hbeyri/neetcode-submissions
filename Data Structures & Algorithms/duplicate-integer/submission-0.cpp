class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        s.reserve(nums.size());
        for(int v : nums)
        {
            if(s.contains(v))
            {
                return true;
            }
            s.insert(v);
        }
        return false;
    }
};