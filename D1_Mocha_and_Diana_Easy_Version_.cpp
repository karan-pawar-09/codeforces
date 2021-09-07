/*
author:Karan
created:15.08.2021 21:19:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

struct DSU {
    vector<ll> parent;
    vector<ll> magnitude;
    DSU(ll n) {
        parent.resize(n+1);
        magnitude.resize(n+1);
        for(ll i=1;i<=n;i++) {
            make_set(i);
        }
    }
    ll find(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void make_set(ll v) {
        parent[v] = v;
        magnitude[v] = 1;
    }

    void merge(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (magnitude[a] < magnitude[b])
                swap(a, b);
            parent[b] = a;
            magnitude[a] += magnitude[b];
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m1,m2;
    cin>>n>>m1>>m2;
    vector<ll> parent1(n+1),magnitude1(n+1),parent2(n+1),magnitude2(n+1);
    DSU dsu1(n),dsu2(n);
    ll a,b;
    for(ll i=0;i<m1;i++) {
        cin>>a>>b;
        dsu1.merge(a,b);
    }
    for(ll i=0;i<m2;i++) {
        cin>>a>>b;
        dsu2.merge(a,b);
    }
    vector<pair<ll,ll>> ans;
    for(ll i=1;i<=n;i++) {
        for(ll j=i+1;j<=n;j++) {
            if((dsu1.find(i)!=dsu1.find(j)) and (dsu2.find(i)!=dsu2.find(j))) {
                ans.push_back({i,j});
                dsu1.merge(i,j);
                dsu2.merge(i,j);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) {
        cout<<x.first<<" "<<x.second<<endl;
    }
}