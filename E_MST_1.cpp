/*
    author:Karan
    created:15.01.2022 18:56:55
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

const ll mx=(ll) 2e5+7;
ll parent[mx];
ll magnitude[mx];

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(ll v) {
    parent[v] = v;
    magnitude[v] = 1;
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (magnitude[a] < magnitude[b])
            swap(a, b);
        parent[b] = a;
        magnitude[a] += magnitude[b];
    }
}

void solve() {
    ll n,m,q;
    cin>>n>>m>>q;
    for(ll i=1;i<=n;i++) {
        make_set(i);
    }
    vector<pair<ll,pair<ll,ll>>> arr(m);
    for(ll i=0;i<m;i++) {
        cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
    }
    sort(all(arr));
    ll ans=0;
    set<pair<ll,ll>> s;
    map<pair<ll,ll>,ll> M;
    ll maxi=0;
    for(ll i=0;i<m;i++) {
        if(find_set(arr[i].second.first)!=find_set(arr[i].second.second)) {
            s.insert(arr[i].second);
            M[arr[i].second]=arr[i].first;
            maxi=max(maxi,arr[i].first);
            ans+=arr[i].first;
            union_sets(arr[i].second.second,arr[i].second.first);
        }
    }
    while(q--) {
        ll a,b,c;
        cin>>a>>b>>c;
        if(s.find({a,b})!=s.end()) {
            if(M[{a,b}]>=c) {
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
        } else {
            if(c<=maxi) {
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}