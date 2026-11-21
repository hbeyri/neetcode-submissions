class Solution {
public:
    bool isAlphaNum(char c)
    {
        return (c>='a' && c<='z')
            || (c>='A' && c<='Z')
            || (c>='0' && c<='9');
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right)
        {
            while(left<s.size() && !isAlphaNum(s[left]))
                ++left;
            while(right>=0 && !isAlphaNum(s[right]))
                --right;
            if(left<right && tolower(s[left]) != tolower(s[right]))
                return false;
            ++left;
            --right;
        }

        return true;
    }
};
