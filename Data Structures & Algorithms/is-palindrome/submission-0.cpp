class Solution {
public:
    bool isAlphaNumeric(char c) const
    {
        return (c>='a' && c<='z')
            || (c>='A' && c<='Z')
            || (c>='0' && c<='9');
    }

    bool isPalindrome(string s) {
        if(s.size() == 1)
            return true;
        int left = 0;
        int right = s.size()-1;
        while(left<right)
        {
            while(!isAlphaNumeric(s[left]))
            {
                ++left;
                if(left>=s.size())
                    return true;
            }
            while(!isAlphaNumeric(s[right]))
                --right;

            //cout<<s[left]<<" "<<s[right]<<endl;
            if(tolower(s[left])!=tolower(s[right]))
                return false;
            ++left;
            --right;
        }

        return true;
    }
};
