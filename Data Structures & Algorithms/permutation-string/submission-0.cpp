class Solution {
public:
    bool check(int freq_a[], int freq_b[])
    {
        for(int i=0;i<256;++i)
        {
            if(freq_a[i]!=freq_b[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        
        int freq[256] = {};
        for(char c : s1)
        {
            ++freq[c];
        }

        int freq_sliding[256] = {};
        for(int i=0;i<s1.size();++i)
        {
            char c = s2[i];
            ++freq_sliding[c];
        }
        if(check(freq, freq_sliding))
            return true;

        for(int i=s1.size();i<s2.size();++i)
        {
            char head_c = s2[i];
            ++freq_sliding[head_c];
            char tail_c = s2[i-s1.size()];
            --freq_sliding[tail_c];
            if(check(freq, freq_sliding))
                return true;
        }

        return false;
    }
};
