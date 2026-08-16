class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b)
        {
            return a[2] < b[2];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
        for(const auto& point : points)
        {
            int sqrDist = point[0]*point[0] + point[1] * point[1];
            pq.push({point[0], point[1], sqrDist});
            if(pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ret;
        while(!pq.empty())
        {
            vector<int> val = pq.top();
            pq.pop();
            ret.push_back({val[0], val[1]});
        }
        return ret;
    }
};
