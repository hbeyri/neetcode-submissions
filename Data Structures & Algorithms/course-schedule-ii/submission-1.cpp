class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> in_edges(numCourses);
        
        for(const auto& prereq : prerequisites)
        {
            edges[prereq[1]].push_back(prereq[0]);
            ++in_edges[prereq[0]];
        }

        queue<int> q;
        for(int i=0;i<numCourses;++i)
        {
            if(in_edges[i]==0)
                q.push(i);
        }

        vector<int> ret;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            ret.push_back(n);
            for(int next : edges[n])
            {
                --in_edges[next];
                if(in_edges[next] == 0)
                    q.push(next);
            }
        }

        return ret.size() == numCourses ? ret : vector<int>();
    }
};
