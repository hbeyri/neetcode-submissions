class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ret = 0;
        while(left+1<height.size() && height[left] <= height[left+1])
            ++left;
        while(right-1>=0 && height[right] <= height[right-1])
            --right;
        
        while(left<right-1)
        {
            int minheight = min(height[left], height[right]);
            int dir = height[left]<=height[right] ? 1:-1;
            int cur = height[left]<=height[right] ? left:right;
            cur += dir;
            while(cur>left && cur<right && height[cur] <= minheight)
            {
                ret += minheight-height[cur];
                cur += dir;
            }

            if(cur<=left || cur>=right)
                break;
            else if(dir == 1)
                left = cur;
            else
                right = cur;
        }

        return ret;
    }
};
