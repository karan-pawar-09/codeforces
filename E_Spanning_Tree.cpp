/*
author:Karan
created:10.06.2021 18:03:26
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++) {
        make_set(i);
    }
    vector<pair<ll,pair<ll,ll>>> arr(m);
    for(ll i=0;i<m;i++) {
        cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
    }
    sort(all(arr));
    ll ans=0;
    for(ll i=0;i<m;i++) {
        if(find_set(arr[i].second.first)!=find_set(arr[i].second.second)) {
            ans+=arr[i].first;
            union_sets(arr[i].second.second,arr[i].second.first);
        }
    }
    cout<<ans<<endl;
}