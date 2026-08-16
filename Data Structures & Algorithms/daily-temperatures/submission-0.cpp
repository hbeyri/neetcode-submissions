class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ret;
        int n = temp.size();
        ret.resize(n);
        stack<pair<int,int>> st;

        for(int i=0;i<n-1;++i)
        {
            if(temp[i] < temp[i+1])
            {
                ret[i] = 1;
                while(!st.empty() && st.top().first < temp[i+1])
                {
                    auto [v, index] = st.top();
                    ret[index] = i+1-index;
                    st.pop();
                }
            }
            else
            {
                st.push({temp[i], i});
            }
        }

        while(!st.empty())
        {
            auto [val, index] = st.top();
            ret[index] = 0;
            st.pop();
        }

        ret[n-1] = 0;
        return ret;
    }
};
