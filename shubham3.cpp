/*
author:Karan
created:13.06.2021 17:15:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int maxx = 2e5+7;
vector<int> tree[maxx];
int degree_of_node[maxx], parent_of_node[maxx],child_of_node[maxx], flag = -1;

void dfs(int current, int parent) {
    parent_of_node[current] = parent;
    for (int& child : tree[current]) {
        if (child == parent)
            return;
        dfs(child, current);
    }
    if (degree_of_node[current] == 1 && current != 1) {
        child_of_node[current] = 0;
        return;
    }
    int total_child = 0;
    for (auto& child : tree[current]) {
        if (child == parent)
            return;
        else
            ++total_child;
    }
    child_of_node[current] = total_child;
    return;
}
  
// Function to calculate permuations ( nPr )
int find_nPr(int N, int R) {
    if (R > N) {
        flag = 0;
        return 0;
    }
    int total = 1;
    for (int i = N - R + 1; i <= N; ++i) {
        total = total * i;
    }
    return total;
}
  
int NoOfWays(int Nodes, int colors,int parent) {
    dfs(parent, -1);
    int ways = 1;
    for (int i = 1; i <= Nodes; ++i) {
        if (i == 1) {
            // ways = ways + colors *  find_nPr(colors - 1, child_of_node[1]);
        }
        else {
            if (degree_of_node[i] == 1) {
                continue;
            }
            else {
                ways = ways * 2;
            }
        }
    }
    return ways;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int start;
    cin>>start;
    int u,v;
    for(int i=0;i<n-1;i++) {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        degree_of_node[u]++;
        degree_of_node[v]++;
    }
    int count=NoOfWays(n,2,start);
    cout<<count<<endl;
}