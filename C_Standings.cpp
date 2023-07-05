/*
    author:Karan
    created:01.07.2023 17:38:11
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

bool comp(pair<pair<ll, ll>, ll> & a, pair<pair<ll, ll> ,ll> & b) {
    if ((a.first.first * (b.first.first + b.first.second) > (b.first.first * (a.first.first + a.first.second)))) {
        return true;
    }
    else if ((a.first.first * (b.first.first + b.first.second) < (b.first.first * (a.first.first + a.first.second)))) {
        return false;
    }
    else {
        return a.second < b.second;
    }
}
void solve() {
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i+1;
    }
    sort(all(arr), comp);
    for(auto x: arr) {
        cout<<x.second<<" ";
    }
    cout<<endl;
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