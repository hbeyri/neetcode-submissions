class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        int pivot = nums.size();
        while(pivot != k-1)
        {
            pivot = partition(nums, left, right);
            cout<<pivot<<endl;
            if(pivot > k-1)
                right = pivot-1;
            else
                left = pivot+1;
        }
        return nums[k-1];
    }

    int partition(vector<int>& nums, int left, int right)
    {
        int pivot_index = right;
        int i=left;
        for(int j=left;j<right;++j)
        {
            if(nums[j]>nums[pivot_index])
            {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[pivot_index]);
        return i;
    }
};
