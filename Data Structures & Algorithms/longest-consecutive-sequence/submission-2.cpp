class Solution {
public:

    int buckets[256] = {};
    vector<int> temp;

    void countingSortByByte(vector<int>& nums, int shift)
    {
        temp.resize(nums.size());
        fill(begin(buckets), end(buckets), 0);
        for(int i=0;i<nums.size();++i)
        {
            int v = (nums[i] >> shift) & 0xFF; // grab the last byte
            ++buckets[v];
        }

        // prefix sum
        for(int i=1;i<256;++i)
        {
            buckets[i] += buckets[i-1];
        }

        // iterate backwards cause prefix sum records the place for the last element with that bucket
        for(int i=nums.size()-1;i>=0;--i)
        {
            int v = (nums[i] >> shift) & 0xFF; // grab the last byte
            temp[--buckets[v]] = nums[i];        
        }
        nums = temp;
    }

    vector<int> radixSort(vector<int>& nums)
    {
        vector<int> ret = nums;

        // flip MSB
        for(int i=0;i<ret.size();++i)
        {
            ret[i] = ret[i] ^ 0x80000000;
        }

        for(int i=0;i<4;++i)
        {
            countingSortByByte(ret, i*8);
        }

        // flip MSB back
        for(int i=0;i<ret.size();++i)
        {
            ret[i] = ret[i] ^ 0x80000000;
        }

        return ret;
    }

    template<typename T>
    void print(T& nums)
    {
        for(int v:nums)
            cout<<v<<" ";
        cout<<endl;
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;

        vector<int> sorted = radixSort(nums);
        print(sorted);
        int longest = 1;
        int current = 1;
        for(int i=1;i<sorted.size();++i)
        {
            int diff = sorted[i]-sorted[i-1];
            if(diff == 1)
            {
                ++current;
                longest = max(longest, current);
            }
            else if(diff!=0)
            {
                current = 1;
            }
        }

        return longest;
    }
};
