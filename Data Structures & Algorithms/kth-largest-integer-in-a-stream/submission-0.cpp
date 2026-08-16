class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int mK;

    KthLargest(int k, vector<int>& nums) {
        mK = k;
        for(int v : nums)
        {
            pq.push(v);
            if(pq.size() > mK)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > mK)
            pq.pop();
        return pq.top();
    }
};
