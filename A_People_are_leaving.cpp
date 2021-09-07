/*
author:Karan
created:21.07.2021 20:52:54
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=1e6+7;
int parent[mx];

int find(int a) {
    if (parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void make(int i) {
    parent[i]=i;
}
void merge(int a,int b) {
    int u=find(parent[a]);
    int v=find(parent[b]);
    if(u!=v) {
        parent[u]=v;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;   

    for(int i=1;i<=n+1;i++) {
        make(i);
    }

    while(m--) {
        char k;
        int p;
        cin>>k>>p;
        if(k=='-') {
            merge(p,p+1);
        }
        else {
            find(p)==(n+1)?cout<<-1<<endl:cout<<find(p)<<endl;
        }
    }
}