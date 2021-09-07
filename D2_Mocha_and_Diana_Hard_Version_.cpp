/*
author:Karan
created:16.08.2021 15:27:56
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
        if((dsu1.find(1)!=dsu1.find(i)) and (dsu2.find(i)!=dsu2.find(1))) {
            ans.push_back({1,i});
            dsu1.merge(i,1);
            dsu2.merge(i,1);
        }        
    }
    vector<bool> visited(n+1,false);
    ll l=1;
    ll r=1;
    while((l<=n) and (r<=n)) {
        while(l<=n and ((dsu1.find(l)==dsu1.find(1))|| visited[dsu1.find(l)])) l++;
        while(r<=n and ((dsu2.find(r)==dsu2.find(1))|| visited[dsu2.find(r)])) r++;
        if(l>n || r>n) break;
        visited[dsu1.find(l)]=visited[dsu2.find(r)]=true;
        ans.push_back({l,r});
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) {
        cout<<x.first<<" "<<x.second<<endl;
    }
}