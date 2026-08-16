class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
            switch(c)
            {
                case '{':
                case '[':
                case '(':
                st.push(c);
                continue;
                break;
            }

            if(st.empty()
                || (c == '}' && st.top() != '{')
                || (c==']' && st.top() != '[')
                || (c==')' && st.top() != '(')
                )
                return false;
            else
                st.pop();
        }

        return st.empty();
    }
};
