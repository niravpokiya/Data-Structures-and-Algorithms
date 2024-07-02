#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent , rank;

    public :

    DisjointSet(int n)
    {
        rank.assign(n + 1, 0);
        parent.assign(n + 1, 0);

        for(int i = 0; i <= n; i++)
        parent[i] = i;
    }

    int findparent(int u)                            //for finding greatest parent of current node
    {
        if(parent[u] == u)
         return u;
        return parent[u] = findparent(parent[u]);
    }
    
    void unionByrank(int u , int v)
    {
        int par_u = findparent(u);
        int par_v = findparent(v);

        if(par_u == par_v) return;
        else if(rank[par_u] < rank[par_v])
        {
            parent[par_u] = par_v;
        }
        else if(rank[par_u] > rank[par_v])
        {
            parent[par_v] = par_u;
        }
        else{
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};

int main()
{
    DisjointSet Ds(7);
    Ds.unionByrank(1, 2);
    Ds.unionByrank(2, 3);
    Ds.unionByrank(4, 5);
    Ds.unionByrank(6, 7);
    Ds.unionByrank(5, 6);

    if(Ds.findparent(6) == Ds.findparent(7)) cout <<"YES Both belongs to same component";
    else cout << "No both belongs to different components";
    
}