#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
                          // kahn's algorithm
void topologicalSort(int V, const vector<vector<int>>& graph) {
    vector<int> ans;
         vector<int> G[V];
         for(auto it : graph)
         {
             G[it[0]].push_back(it[1]);
         }
        vector<int> indegree(V, 0);
        
        for(auto it : graph)
        indegree[it[1]]++;
        queue<int> q;
        for(int i = 0 ; i < V; i++)
        if(indegree[i] == 0) q.push(i);
        
        while(!q.empty())
        {
            int top = q.front() ; q.pop();
            ans.push_back(top);
            for(int i : G[top])
            {
                indegree[i]--;
               
                if(indegree[i] == 0) q.push(i);
            }
        }
         reverse(ans.begin() , ans.end());

         if(ans.size() == V) {}// possible
         else{} // not possible contais cycle
}

int main() { 
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort of the given graph is: \n";
    topologicalSort(V, adj);

    return 0;
}
