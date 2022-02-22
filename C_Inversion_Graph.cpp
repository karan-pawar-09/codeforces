/*
    author:Karan
    created:14.02.2022 21:42:23
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
    int n;
    cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++) {
        s.insert(i);
    }
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    DSU dsu=DSU(n+10);
    for(int i=0;i<n;i++) {
        s.erase(arr[i]);
        for(auto x:s) {
            if(x<arr[i]) {
                dsu.merge(arr[i],x);
            } else {
                break;
            }
        }
    }
    set<int> ans;
    for(int i=1;i<=n;i++) {
        ans.insert(dsu.find(i));
    }
    cout<<ans.size()<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}