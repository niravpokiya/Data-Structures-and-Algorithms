#include<bits/stdc++.h>
using namespace std;
#define N 200004
vector<int> g[N];
int maxheight = 0;
int dfs(int curr, int par = -1, int h = 1)
{
    h++;
    for(int i : g[curr])
    {
        if(i == par) continue;
        dfs(i , curr, h);
        maxheight = max(maxheight, h);
    }
    return maxheight;
}
int main()
{
     int n;
     cin >> n;
     for(int i = 0; i < n - 1; i++)
    {
         int a , b;
         cin >> a >> b;
         g[a].push_back(b);
         g[b].push_back(a);
    }
    dfs(1);
    cout << maxheight << endl;
}