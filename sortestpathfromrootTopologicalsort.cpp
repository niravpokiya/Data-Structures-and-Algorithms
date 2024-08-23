

#include <bits/stdc++.h>
using namespace std;

     //sortest path from root 0 by using topological sort

class Solution {
  void dfs(vector<pair<int, int>> g[], int top, vector<bool> &vis, stack<int> &s) {
    vis[top] = true; 
    for(auto i : g[top])
      if(!vis[i.first])
        dfs(g, i.first, vis, s);
     
     s.push(top);
  }
  
  public:
  vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    vector<pair<int, int>> g[N];
    for(auto edge : edges) {
      g[edge[0]].push_back({edge[1], edge[2]});
    }
    
    vector<bool> vis(N, false);
    stack<int> topo;
    for(int i = 0; i < N; i++)
      if(!vis[i])
        dfs(g, i, vis, topo);
        
    vector<int> dis(N, INT_MAX);
    dis[0] = 0;
    while(!topo.empty()) {
      int top = topo.top();
      topo.pop(); 
        for(auto i : g[top]) {
          int u = top; 
          int v = i.first;
          int wt = i.second;
          if(dis[u] + wt < dis[v]) {
            dis[v] = dis[u] + wt;
        }
      }
    }
    
    // Set unreachable nodes to -1
    for (int i = 0; i < N; i++) {
      if (dis[i] == INT_MAX) {
        dis[i] = -1;
      }
    }

    return dis;
  }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}