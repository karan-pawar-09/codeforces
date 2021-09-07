/*
author:Karan
created:07.06.2021 12:30:13
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=(int)1e5+7;
int parent[mx];
int magnitude[mx];

ll get(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

void init(ll v) {
    parent[v] = v;
    magnitude[v] = 1;
}

void union_set(ll a, ll b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (magnitude[a] < magnitude[b])
            swap(a, b);
        parent[b] = a;
        magnitude[a] += magnitude[b];
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
        cin>>s>>u>>v;
        if(s=="union") {
            union_set(u,v);
        } else {
            get(u)==get(v)?cout<<"YES"<<endl:cout<<"NO"<<endl;
        }
    }
}