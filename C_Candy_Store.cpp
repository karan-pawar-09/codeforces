/*
    author:Karan
    created:26.03.2023 21:32:05
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

ll lcm(ll a, ll b) {
    return (a/__gcd(a,b)) * b;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    DSU dsu = DSU(n+10);
    ll _ = 1;
    while(_--) {
        for(ll i=1;i<n;i++) {
            if(true) {
                ll a = __gcd(arr[dsu.find(i-1)].first * arr[dsu.find(i-1)].second, arr[dsu.find(i)].first * arr[dsu.find(i)].second);
                ll b = lcm(arr[dsu.find(i-1)].second, arr[dsu.find(i)].second);
                if(a % b == 0) {
                    dsu.merge(i-1, i);
                    arr[dsu.find(i)].first = a;
                    arr[dsu.find(i)].second = b;
                }
            }
        }
    }
    set<ll> s;
    for(ll i=0;i<n;i++) {
        s.insert(dsu.find(i));
    }
    cout<<s.size()<<endl;
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