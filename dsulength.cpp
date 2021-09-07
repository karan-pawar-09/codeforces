/*
author:Karan
created:09.06.2021 20:36:55
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<pair<int,int>> parent;
vector<int> rnk;

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rnk[v] = 0;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = make_pair(a, 1);
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    parent.resize(n);
    rnk.resize(n);
    for(int i=0;i<n;i++) {
        make_set(i);
    }
    while(m--) {
        int u,v;
        cin>>u>>v;
        union_sets(u,v);
    }
    cout<<parent[2].second;
    cout<<parent[1].second;
    cout<<find_set(1).first<<endl;
    cout<<"O"<<endl;
}