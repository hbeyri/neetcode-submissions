struct VectorHash {
    std::size_t operator()(const std::vector<int>& v) const noexcept {
        std::size_t seed = v.size();  // seed with size helps distinguish {1,2} from {1,2,0}-like collisions
        for (int x : v) {
            std::size_t h = std::hash<int>{}(x);
            seed ^= h + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
 
    vector<vector<int>> findTargetPair(vector<int>& nums, int target, int exclude_index)
    {
        vector<vector<int>> ret;
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] > target)
            return {};
        while(left<right)
        {
            if(left == exclude_index){
                ++left;
                continue;
            }
            else if(right == exclude_index){
                --right;
                continue;
            }

            int sum = nums[left] + nums[right];
            if(sum > target)
            {
                --right;
            }
            else if(sum < target)
            {
                ++left;
            }
            else if (sum == target)
            {
                ret.push_back({nums[exclude_index], nums[left], nums[right]});
                ranges::sort(ret.back());
                ++left;
            }
        }
        return ret;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> s;
        vector<vector<int>> ret;
        ranges::sort(nums);
        for(int i=0;i<nums.size();++i)
        {
            int target = -nums[i];
            auto triplets = findTargetPair(nums, target, i);
            for(const auto& triplet : triplets)
            {
                s.insert(triplet);
            }
        }

        for(auto& v : s)
        {
            ret.push_back(v);
        }

        return ret;
    }
};
