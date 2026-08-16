class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ret = 0;
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            int hleft = heights[left];
            int hright = heights[right];
            ret=max(ret, min(hleft, hright)*(right-left));
            if(hleft<hright)
                ++left;
            else if(hleft>hright)
                --right;
            else
            {
                ++left;
                --right;
            }
        }

        return ret;
    }
};
