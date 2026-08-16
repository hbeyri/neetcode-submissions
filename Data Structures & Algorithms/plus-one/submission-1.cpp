class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;--i)
        {
            if(digits[i]!=9)
            {
                ++digits[i];
                return digits;
            }
            digits[i]=0;
        }
        vector<int> ret(digits.size()+1);
        ret[0] = 1;
        return ret;
    }
};
