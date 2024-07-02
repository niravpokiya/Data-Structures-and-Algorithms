#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

//  Tarjan's Algorithm for finding bridges of graph


istream& operator >>(istream & io , vi &v) {
    for(int i = 0; i < v.size(); i++)
        io >> v[i];
    return io;
}
ostream& operator <<(ostream & io , vi &v) {
    for(int i = 0; i < v.size(); i++)
        io << v[i] << " ";
    return io;
}


int t = 1;
vector<int> g[100004];
void dfs(int top , int parent, vector<int> g[] , vector<bool> & vis ,
         vector<vector<int>> &ans, int low[], int tin[], int reachable[]){
    vis[top]=true;
    low[top] = tin[top] = t++;
    reachable[top] = 1;
    for(int i  :  g[top])
    {
        if(i == parent) {continue;}
        if(!vis[i]){
             dfs(i, top, g, vis, ans, low, tin, reachable);
             low[top]  = min(low[top] , low[i]);
             reachable[top] +=  reachable[i];
             if(tin[top] < low[i]){
             ans.push_back({top , i});
        }
        }
        else{
             low[top]  = min(low[top] , low[i]);
        }
    }
}

vector<vector<int>> Bridges(int n, vector<vector<int>>& connections) {
        for(auto it : connections)
          {
              g[it[0]].push_back(it[1]);
              g[it[1]].push_back(it[0]);
          }
        vector<bool> vis(n + 1, false);
        int tin[n + 1];
        int low[n + 1];
        int reachable[n + 1];
        vector<vector<int>> ans;
        dfs(1, -1, g, vis, ans, low, tin, reachable);
        return ans;
}

void done_boss() {
      int n , m; cin >> n >> m ;
      t = 1;
      vector<vector<int>> v(m , vector<int>(2, 0));
      for(auto & i : v) cin >> i;
      for(int i = 0 ; i < n  + 1; i++) g[i].clear();
      vector<bool> vis(n + 1 , false);
      vector<vector<int>>  ans = Bridges(n , v);

       for(auto it : ans) cout << it << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        done_boss();
    }

    return 0;
}