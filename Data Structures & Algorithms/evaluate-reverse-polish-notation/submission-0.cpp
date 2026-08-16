class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();++i)
        {
            const string& token = tokens[i];
            if(token == "+"
                || token == "-"
                || token == "*"
                || token == "/"
                )
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                if(tokens[i] == "+")
                    st.push(a+b);
                else if(tokens[i]== "-")
                    st.push(a-b);
                else if(tokens[i] == "*")
                    st.push(a*b);
                else if(tokens[i]=="/")
                    st.push(a/b);
            }
            else 
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }

        return st.top();
    }
};
