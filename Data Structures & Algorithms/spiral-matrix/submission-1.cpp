class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        while(top<=bottom && left<=right)
        {
            cout<<top<<" "<<bottom<<" "<<left<<" "<<right<<endl;
            cout<<ret.size()<<endl;
            for(int i=left;i<=right;++i)
                ret.push_back(matrix[top][i]);
            for(int i=top+1;i<=bottom;++i)
                ret.push_back(matrix[i][right]);
            if(top != bottom)
            {
                for(int i=right-1;i>=left;--i)
                    ret.push_back(matrix[bottom][i]);
                if(left != right)
                {
                    for(int i=bottom-1;i>=top+1;--i)
                        ret.push_back(matrix[i][left]);
                }
            }

            ++top;--bottom;
            ++left;--right;
        }

        return ret;
    }
};
