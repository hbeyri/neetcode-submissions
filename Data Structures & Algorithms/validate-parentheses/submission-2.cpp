class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        unordered_map<char, char> closem;
        closem[')'] = '(';
        closem['}'] = '{';
        closem[']'] = '[';
        for(char c:s)
        {
            if (c == '(' || c == '{' || c=='[')
                st.push_back(c);
            else
            {
                char openc = closem[c];
                if(!st.empty() && st.back() == openc)
                {
                    st.pop_back();
                    continue;
                }
                
                return false;
            }
        }

        return st.size() == 0;
    }
};
