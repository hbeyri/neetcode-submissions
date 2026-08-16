class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftmax = height[left];
        int rightmax = height[right];
        int ret = 0;
        while(left<right)
        {
            if(leftmax<rightmax)
            {
                ++left;
                leftmax = max(leftmax, height[left]);
                ret += leftmax - height[left];
            }
            else
            {
                --right;
                rightmax = max(rightmax, height[right]);
                ret += rightmax - height[right];
            }
        }

        return ret;
    }
};
