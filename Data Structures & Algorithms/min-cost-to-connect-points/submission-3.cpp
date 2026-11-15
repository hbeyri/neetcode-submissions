class UnionFind
{
public:
    UnionFind(int n)
    : parents(n)
    , sizes(n, 1)
    {
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int k)
    {
        int root = k;
        while(root != parents[root])
        {
            root = parents[root];
        }
        while(root != parents[k])
        {
            int next = parents[k];
            parents[k] = root;
            k = next;
        }

        return root;
    }

    bool unite(int a, int b)
    {
        // bool test = a == 1 && b == 2;
        a = find(a);
        b = find(b);
        // if(test)
        //     cout<<"check sizes: "<<sizes[root_a] << " " << sizes[root_b]<<endl;

        if(a == b)
            return false;
        if(sizes[a] < sizes[b])
            swap(a, b);
        parents[b] = a;
        sizes[a] += sizes[b];
        // cout<<"updated size "<<a<<" : "<<sizes[a]<<endl;
        return true;
    }

    bool connected(int a, int b)
    {
        return find(a) == find(b);
    }
private:
    vector<int> parents;
    vector<int> sizes;
};

class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UnionFind uf(n);
        vector<vector<int>> edges;
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int delt_x = points[i][0] - points[j][0];
                int delt_y = points[i][1] - points[j][1];
                int dist = abs(delt_x) + abs(delt_y);
                edges.push_back({i, j, dist});
            }
        }
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
            return a[2] < b[2];
        });
        
        int ret = 0;
        cout<<edges.size()<<endl;
        for(const auto& edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            // cout<<a<<" "<<b<<" "<<edge[2]<<" "<<uf.find(a)<<" "<<uf.find(b)<<endl;
            if(!uf.connected(a, b))
            {
                int dist = edge[2];
                ret += dist;
                uf.unite(a, b);
                // cout<<"connect! "<<a<<" "<<b<<endl;
                // cout<<"new root: "<<uf.find(a)<<" "<<uf.find(b)<<endl;
                // cout<<"new root for "<<a<<" : "<<uf.find(a)<<endl;
                // cout<<"new root for "<<b<<" : "<<uf.find(b)<<endl;
            }
        }

        return ret;
    }
};
