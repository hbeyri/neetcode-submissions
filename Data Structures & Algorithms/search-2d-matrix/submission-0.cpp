class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2; // avoid overflow
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int minrow =0;
        int maxrow = rows-1;

        while(minrow<=maxrow)
        {
            if(minrow==maxrow)
            {
                cout<<"binary "<<minrow<<endl;
                return search(matrix[minrow], target);
            }
            else
            {
                int row = (minrow + maxrow)/2;
                int row_min = matrix[row][0];
                int row_max = matrix[row][cols-1];
                cout<<row_min<<" "<<row_max<<endl;
                if(row_min <= target && target<=row_max)
                    minrow = maxrow = row;
                else if(target<row_min)
                    maxrow = row-1;
                else if(target>row_max)
                    minrow = row+1;
            }
        }
        
        return false;
    }
};
