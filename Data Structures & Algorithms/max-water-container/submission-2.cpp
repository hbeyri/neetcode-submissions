class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ret = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left<right)
        {
            int minh = min(heights[left], heights[right]);
            int area = minh * (right-left);
            ret = max(ret, area);
            if(heights[left] < heights[right])
                ++left;
            else
                --right;
        }

        return ret;
    }
};
