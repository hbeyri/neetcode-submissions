class Solution {
public:
    string cur;
    vector<string> ret;
    string m[10];

    void backtrack(const string& digits, int i)
    {
        if(i>=digits.size())
        {
            ret.push_back(cur);
            return;
        }

        const string& s = m[digits[i]-'0'];
        for(char c : s)
        {
            cur.push_back(c);
            backtrack(digits, i+1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        backtrack(digits, 0);
        return ret;
    }
};
