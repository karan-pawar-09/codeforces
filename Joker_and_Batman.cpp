/*
author:Karan
created:24.07.2021 14:22:06
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx=1e5+7;
vector<ll> parent,magnitude;

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
    ll n,m,l;
    cin>>n>>m>>l;
    parent.resize(n+1);
    magnitude.resize(n+1);
    for(ll i=0;i<=n;i++) {
        make_set(i);
    }
    while(m--) {
        ll k;
        cin>>k;
        ll a,b;
        cin>>a;
        for(ll i=1;i<k;i++) {
            cin>>b;
            union_sets(a,b);
        }       
    }
    ll ans=1;
    vector<ll> arr(l);
    for(ll i=0;i<l;i++) {
        cin>>arr[i];
        if(i>0) {
            if(find_set(arr[i])!=find_set(arr[i-1])) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}