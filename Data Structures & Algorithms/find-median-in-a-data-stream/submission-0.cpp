class MedianFinder {
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || left.top() > num)
            left.push(num);
        else
            right.push(num);

        // cout<<"before "<<left.size()<<" "<<right.size()<<endl;
        if(left.size() > 1 + right.size())
        {
            int v = left.top();
            left.pop();
            right.push(v);
        }
        else if(right.size() > left.size())
        {
            int v = right.top();
            right.pop();
            left.push(v);
        }
        // cout<<"after "<<left.size()<<" "<<right.size()<<endl;
    }
    
    double findMedian() {
        // cout<<"median "<<left.size()<<" "<<right.size()<<endl;
        if(left.size() == right.size())
            return (left.top() + right.top()) * 0.5;
        else
            return left.top();
    }
};
