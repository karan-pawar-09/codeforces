/*
author:Karan
created:19.06.2021 17:45:41
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx = (ll) 2e5+7;
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        make_set(arr[i]);
    }
    ll ans=0;
    for(ll i=0;i<n/2;i++) {
        if(find_set(arr[i])!=find_set(arr[n-1-i])) {
            ans++;
            union_sets(arr[i],arr[n-1-i]);
        }
    }
    cout<<ans<<endl;
}