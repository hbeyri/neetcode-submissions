class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> in_edges(numCourses);
        for(const auto& prereq : prerequisites)
        {
            int a = prereq[0];
            int b = prereq[1];
            in_edges[a].insert(b);
        }

        queue<int> q;
        vector<bool> visited(numCourses, false);
        for(int i=0;i<numCourses;++i)
        {
            if(in_edges[i].size()==0)
            {
                q.push(i);
                visited[i] = true;
            }
        }

        while(!q.empty())
        {
            int n = q.front();
            q.pop();

            for(int i=0;i<numCourses;++i)
            {
                if(i==n)
                    continue;
                if(!visited[i])
                {
                    in_edges[i].erase(n);
                    if(in_edges[i].size() == 0)
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }

        for(int i=0;i<numCourses;++i)
        {
            if(visited[i]==false)
                return false;
        }
        return true;
    }
};
