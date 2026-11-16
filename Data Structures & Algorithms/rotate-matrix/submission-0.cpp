class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for(int i=0;i<n/2;++i)
        {
            int first = i;
            int last = n-1-i;
            // cout<<"test "<<first<<" "<<last<<endl;
            for(int j=0;j<last-first;++j)
            {
                // cout<<"rotate"<<endl;
                int top[2] = {first, first+j};
                int right[2] = {first+j, last};
                int bottom[2] = {last, last-j};
                int left[2] = {last-j, first};
                int& a = m[top[0]][top[1]];
                int& b = m[right[0]][right[1]];
                int& c = m[bottom[0]][bottom[1]];
                int& d = m[left[0]][left[1]];
                int temp = a;
                a = d;
                d = c;
                c = b;
                b = temp;
            }
        }
    }
};
