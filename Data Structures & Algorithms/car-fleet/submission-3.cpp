class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<float, int>> hops;
        hops.resize(n);
        for(int i=0;i<n;++i)
        {
            hops[i] = {(target - position[i]) * 1.0f / speed[i], position[i]};
        }

        sort(hops.begin(), hops.end(), [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

        int ret = 1;
        float minhops = hops[0].first;
        // for(auto& [a, b] : hops)
        // {
        //     cout<<a<<" "<<b<<" X ";
        // }
        // cout<<endl;

        for(int i=1;i<n;++i)
        {
            if(hops[i].first > minhops)
            {
                ++ret;
                minhops = hops[i].first;
            }
        }
        return ret;
    }
};
