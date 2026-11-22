class Solution {
public:
    unordered_map<char, int> s;
    unordered_map<char, int> seen;
    
    bool isComplete()
    {
        for(const auto&[key, value] : s)
        {
            if(s[key] <= 0)
                continue;

            // cout<<"complete? "<<key<<" "<<value<<endl;
            if(seen[key] < value)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string str, string t) {
        int left = 0;
        for(char c : t)
            ++s[c];

        string ret;
        for(int i=0;i<str.size();++i)
        {
            char c = str[i];
            
            if(!ret.empty())
            {
                left = i-(ret.size()-1);
                if(seen[str[left-1]] > 0)
                   --seen[str[left-1]]; 
            }
            // cout<<str.substr(left, i-left+1)<<endl;
            // cout<<"iter : "<<s[c]<<" "<<seen[c]<<endl;
            if(s[c] > 0)
            {
                ++seen[c];
                // cout<<"test "<<c<<" "<<seen[c]<<endl;
                if(isComplete())
                {
                    // cout<<"complete"<<endl;
                    // cout<<seen[str[left]]<<" "<<s[str[left]]<<endl;
                    // cout<<s[str[left]]<<endl;
                    while((left < i) 
                        && (s[str[left]] == 0
                            || seen[str[left]] > s[str[left]])
                    )
                    {
                        // cout<<"shrink"<<endl;
                        if(seen[str[left]] > 0)
                            --seen[str[left]];
                        ++left;
                    }
                    int sublen = i - left + 1;
                    if(ret.empty() || ret.size() > sublen)
                        ret = str.substr(left, sublen);
                }
            }
        }

        return ret;
    }
};
