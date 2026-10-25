class UnionFind
{
    vector<int> parent;

public:
    UnionFind(int n)
    {
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        int root = x;
        while(parent[root] != root)
            root = parent[root];

        while(parent[x] != root)
        {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a==b)
            return false; // already in the same set

        parent[a] = b;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size()+1);

        vector<int> ret;
        for(const auto& edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            if(!uf.unite(a, b))
            {
                ret = edge;
            }
        }

        return ret;
    }
};
