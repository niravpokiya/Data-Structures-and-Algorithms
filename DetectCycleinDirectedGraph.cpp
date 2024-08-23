// detecting cycle in directed graph ...
#include <bits/stdc++.h>
using namespace std;

bool dfs(int curr, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[curr] = pathVis[curr] = 1;
    for (int i : adj[curr])
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[i])
        {
            return true;
        }
    }
    pathVis[curr] = 0;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}

int main()
{
    int n , m ; cin >> n >> m;
    vector<int> Graph[n];
      for(int i= 0 ; i < m ; i++)
       {
           int a, b; 
           cin >> a >> b;
           Graph[a].push_back(b);
       }

       bool isCycle  = isCyclic(n, Graph);
}
