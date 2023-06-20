/*
    author:Karan
    created:19.06.2023 22:34:58
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
        for(ll i=0;i<=n;i++) {
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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<set<ll>> dp(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    DSU dsu = DSU(n+10);
    for(ll i = 0; i < n; i++) {
        dsu.merge(i+1, arr[i]);
        dp[i+1].insert(arr[i]);
        dp[arr[i]].insert(i+1);
    }
    set<ll> st;
    map<ll, vector<ll>> M;
    for(ll i = 1; i <= n; i++) {
        st.insert(dsu.find(i));
        M[dsu.find(i)].push_back(i);
    }
    ll total = st.size();
    ll mergable = 0;
    for(auto x: M) {
        bool tt = false;
        for(auto y: x.second) {
            if(dp[y].size() == 1) tt = true;
        }
        if(tt) {
            mergable++;
        }
    }
    cout<< min((ll)st.size(), (total-mergable) + 1) << " " << st.size() <<endl; 
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}