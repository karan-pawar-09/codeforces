/*
    author:Karan
    created:11.09.2021 17:55:41
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

void solve() {
    ll n,m;
    cin>>n>>m;
    DSU dsu(n+10);
    vector<pair<ll,pair<ll,ll>>> arr(m);
    ll total=0;
    for(ll i=0;i<m;i++) {
        cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
        if(arr[i].first>0)
            total+=arr[i].first;
    }
    sort(all(arr));
    ll ans=0;
    for(ll i=0;i<m;i++) {
        if(dsu.find(arr[i].second.first)!=dsu.find(arr[i].second.second)) {
            if(arr[i].first>0)
                ans+=arr[i].first;
            dsu.merge(arr[i].second.second,arr[i].second.first);
        }
    }
    if(m==n-1) cout<<0<<endl;
    else
        cout<<max(0LL,(total-ans))<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}