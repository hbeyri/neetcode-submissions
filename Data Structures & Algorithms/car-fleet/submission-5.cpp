class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<float, int>> times;
        times.resize(n);
        for(int i=0;i<n;++i)
        {
            times[i] = {(target - position[i]) * 1.0f / speed[i], position[i]};
        }

        sort(times.begin(), times.end(), [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

        int ret = 1;
        float mintimes = times[0].first;
        for(int i=1;i<n;++i)
        {
            if(times[i].first > mintimes)
            {
                ++ret;
                mintimes = times[i].first;
            }
        }
        return ret;
    }
};
