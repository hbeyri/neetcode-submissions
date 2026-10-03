class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto iter = m.find(key);
        if(iter == m.end())
            return "";
        const vector<pair<int, string>>& v = iter->second;
        int min_ts = v.front().first;
        int max_ts = v.back().first;
        if(timestamp>=max_ts)
            return v.back().second;
        else if(timestamp==min_ts)
            return v.front().second;
        else if(timestamp<min_ts)
            return "";
        
        // cout<<"start"<<endl;
        int left = 0;
        int right = v.size()-1;
        int count = 0;
        while(left<=right && count<10)
        {
            // count++;
            int mid = left + (right-left)/2;
            // cout<<left<<" "<<right<<" "<<v[mid].first<<endl;
            if(timestamp == v[mid].first)
                return v[mid].second;
            else if(timestamp > v[mid].first)
                left = mid+1;
            else
                right = mid-1;
        }
        return right >=0 ? v[right].second : "";
    }
};
