/*
author:Karan
created:04.06.2021 11:10:56
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<ll> parent;
vector<ll> size;

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(ll v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        size[b]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        parent.resize(n,-1);
        size.resize(n,0);
        for(ll i=0;i<n;i++) {
            make_set(i);
        }
        for(ll i=0;i<m;i++) {
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            union_sets(a,b);
        }
        ll ans = n * (n - 1);
        for(int i=0;i<n;i++) {
            if(size[i]>1) {
                ans-=size[i]*(size[i]-1);
            }
        }
        cout<<ans<<endl;
        
    }
}