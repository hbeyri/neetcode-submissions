class Solution {
public:
    int calctime(vector<int>& piles, int k)
    {
        int ret = 0;
        for(int v : piles)
        {
            ret += (v + k - 1) / k; // avoid floating point
            // cout<<v<<" "<<k<<" "<<ceil(v*1.0f/k)<<endl;
        }
        return ret;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_k = *max_element(piles.begin(), piles.end()); // fastest
        int min_k = 1;

        while(min_k < max_k)
        {
            int k = min_k + (max_k - min_k) / 2;
            int time = calctime(piles, k);
            // cout<<k<<" "<<time<<endl;
            if(time > h)
                min_k = k+1;
            else
                max_k = k;
        }
        return min_k;
    }
};
