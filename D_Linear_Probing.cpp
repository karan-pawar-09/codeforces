/*
    author:Karan
    created:20.11.2021 18:05:41
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

const ll N=(1<<20);
ll arr[N+10];

struct DSU {
    vector<ll> parent;
    DSU(ll n) {
        parent.resize(n+1);
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
    }

    void merge(ll a, ll b) {
        ll p = find(a);
        ll q = find(b);
        if(q!=p) {
            parent[a]=parent[b];
        }
    }
};

void solve() {
    ll q;
    cin>>q;
    ll t,x;
    mset(arr,-1);
    DSU dsu=DSU(N+10);
    while(q--) {
        cin>>t;
        cin>>x;
        if(t==1) {            
            ll gg=x%N;
            ll p=dsu.find(gg);
            arr[p]=x;
            if(p==(N-1)) {
                dsu.merge(p,0);
            }
            else {
                dsu.merge(p,p+1);
            }
        }
        else {
            ll gg=x%N;
            cout<<arr[gg]<<endl;
        }
    }
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