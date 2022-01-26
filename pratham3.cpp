/*
    author:Karan
    created:25.01.2022 20:59:54
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

bool is_good(ll i, ll j,vector<vector<ll>> &arr) {
    if(i<arr.size() and j<arr[i].size() and arr[i][j]) return true;
    else return false;
}

void solve() {
    ll n,m,k;
    cin>>n;
    vector<ll> p(n);
    for(ll i=0;i<n;i++) {
        cin>>p[i];
    }
    vector<vector<ll>> arr(n);
    
    ll total=0;
    vector<ll> a={1,0,0,-1};
    vector<ll> b={0,-1,1,0};
    for(ll i=0;i<n;i++) {
        m=p[i];
        total+=m;
        for(ll j=0;j<m;j++) {
            cin>>k;
            arr[i].push_back(k);
        }
    }
    vector<vector<ll>> ar=arr;
    ll xx=1;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<ar[i].size();j++) {
            ar[i][j]=xx;
            xx++;
        }
    }
    DSU dsu = DSU(total+10);
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<arr[i].size();j++) {
            for(ll x=0;x<4;x++) {
                if(is_good(i+a[x],j+b[x],arr)) {
                    dsu.merge(ar[i][j],ar[i+a[x]][j+b[x]]);
                }
            }
        }
    }
    set<ll> s;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<arr[i].size();j++) {
            if(arr[i][j]) {
                s.insert(dsu.find(ar[i][j]));
            }
        }
    }
    cout<<s.size()<<endl;
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