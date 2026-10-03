class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int count = 0;
        while(left<=right && count<10) 
        {
            // ++count;
            cout<<left<<" "<<right<<endl;
            int mid = left + (right - left) / 2;
            cout<<"mid "<<mid<<endl;
            if(nums[mid] == target)
                return mid;

            if(nums[left] < nums[right])
            {
                if(target < nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                // rotated
                cout<<"rotated "<< nums[mid] <<" "<< nums[right]<<endl;
                if(nums[mid] < nums[right])
                {
                    if(target<nums[mid] || target>nums[right])
                    {
                        cout<<"check left"<<endl;
                        right = mid-1;
                    }
                    else
                    {
                        cout<<"check right"<<endl;
                        left = mid+1;
                    }
                }
                else
                {
                    if(target>nums[mid] || target<nums[left])
                        left = mid+1;
                    else
                        right = mid-1;
                }


                // if(target>=nums[left] && nums[mid]<nums[left])
                //     right = mid-1;
                // else
                //     left = mid+1;

                // if(nums[left]<=nums[mid] && nums[left]<=target && target<nums[mid])
                //     right = mid-1;
                // else
                //     left = mid+1;
            }
        }

        return -1;
    }
};
