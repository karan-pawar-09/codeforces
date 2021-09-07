/*
author:Karan
created:02.06.2021 21:53:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int N=100;
vector<int> grid[N];
int tin[N],low[N],visited[N];
int timer;
int n,step;
vector<pair<int,int>> ans;

void dfs(int v,int p) {
    visited[v]=1;
    tin[v]=low[v]=step++;
    for(int to:grid[v]) {
        if(to==p) continue;
        if(visited[to]) {
            low[v]=min(low[v],tin[to]);
        }
        else {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>tin[v]) {
                ans.emplace_back(min(to,v),max(to,v));
            }
        }
    }
}
int main()
{
   while(scanf("%d", &n) != EOF){
        timer=0;
        int i, j, u, v;
        for (i = 0; i < n; ++i)
        {
            scanf("%d (%d)", &u, &j);
            while (j--)
            {
                scanf("%d", &v);
                grid[u].push_back(v);
            }
        }

        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i,i);
            }
        }
        sort(ans.begin(), ans.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
                 return a.first < b.first || (a.first == b.first && a.second < b.second);
             });
        printf("%d critical links\n", (int)ans.size());
        for (auto p : ans)
            printf("%d - %d\n", p.first, p.second);
        putchar('\n');

        for (i = 0; i < n; ++i)
            grid[i].clear();
        memset(visited, 0, sizeof visited);
        memset(tin, 0, sizeof tin);
        memset(low, 0, sizeof low);
        ans.clear();
        step = 0;
    }
    
}