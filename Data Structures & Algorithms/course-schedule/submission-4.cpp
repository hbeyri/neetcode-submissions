class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> out_edges(numCourses);
        vector<int> in_count(numCourses);
        for(const auto& prereq : prerequisites)
        {
            int a = prereq[0];
            int b = prereq[1];
            out_edges[b].push_back(a);
            ++in_count[a];
        }

        queue<int> q;
        for(int i=0;i<numCourses;++i)
        {
            if(in_count[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int n = q.front();
            q.pop();

            for(int next : out_edges[n])
            {
                --in_count[next];
                if(in_count[next]==0)
                    q.push(next);
            }
        }

        for(int i=0;i<numCourses;++i)
        {
            if(in_count[i]!=0)
                return false;
        }
        return true;
    }
};
