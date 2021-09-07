/*
author:Karan
created:07.06.2021 12:54:35
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=(int)3e5+7;
int parent[mx];
int magnitude[mx];
int mini[mx];
int maxi[mx];

ll get(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

void init(ll v) {
    parent[v] = v;
    magnitude[v] = 1;
    mini[v]=v;
    maxi[v]=v;
}

void union_set(ll a, ll b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (magnitude[a] < magnitude[b])
            swap(a, b);
        parent[b] = a;
        magnitude[a] += magnitude[b];
        mini[a]=min(mini[a],mini[b]);
        maxi[a]=max(maxi[a],maxi[b]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        init(i);
    }
    while(m--) {
        string s;
        int u,v;
        cin>>s;
        if(s=="union") {
            cin>>u>>v;
            union_set(u,v);
        } else {
            cin>>u;
            int p=get(u);
            cout<<mini[p]<<" "<<maxi[p]<<" "<<magnitude[p]<<endl;
        }
    }
}