#include<bits/stdc++.h>
 using namespace std;
    void dfs(int n, vector<vector<int>> &node, vector<bool> & vis)
    {
        if(vis[n]) return;
             vis[n] = true;
         for(auto i : node[n])
         {
             if(!vis[i])
             dfs(i , node, vis);
         }
    }
    int countconnectedcomponents(int n, vector<vector<int>>& edges) {
         vector<bool> vis(n+ 1, false);
         vector<vector<int>> cv(n + 1);
         for(auto l : edges)
         {
            int j = l[0], k = l[1];
            cv[j].push_back(k);
            cv[k].push_back(j);
         }
         int cnt = 0;
         for(int i = 1; i <= n ; i++)
         {
            if(vis[i]) continue;
            dfs(i, cv,vis);++cnt;
         }
         return cnt;
    }
int main(){
  int n , m;
  cin >> n >> m;
  vector<vector<int>> edge(m , vector<int>(2, 0)); 
  for(auto &j : edge)
  for(auto &i : j) cin >> i;
  cout << countconnectedcomponents(n , edge) << endl;
  return 0;
}