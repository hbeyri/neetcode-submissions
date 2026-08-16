class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void print(const vector<int>& v)
    {
        for(int a : v)
            cout << a << " ";
        cout<<endl;
    }

    void recurse(vector<int>& nums, int start, int target)
    {
        if(target == 0)
        {
            // cout<<"test ";
            // print(cur);
            ret.push_back(cur);
            // m.insert(cur);
            return;
        }

        for(int i=start;i<nums.size();++i)
        {
            if(nums[i] > target)
                break;
            if(i>start && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            recurse(nums, i+1, target-nums[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ret.clear();
        cur.clear();
        sort(candidates.begin(), candidates.end());
        recurse(candidates, 0, target);
        // cout<<ret.size()<<endl;
        return ret;
    }
};
