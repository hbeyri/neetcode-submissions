class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool all_nines = all_of(digits.begin(), digits.end(), [](int k){
            return k == 9;
        });

        if(all_nines)
        {
            vector<int> ret;
            ret.resize(digits.size()+1);
            ret[0] = 1;
            for(int i=1;i<ret.size();++i)
                ret[i] = 0;
            return ret;
        }
        
        vector<int> ret;
        ret.resize(digits.size());
        int carry = 1;
        for(int i=digits.size()-1;i>=0;--i)
        {
            int digit = digits[i] + carry;
            ret[i] = digit % 10;
            carry = digit/10;
        }
        return ret;
    }
};
