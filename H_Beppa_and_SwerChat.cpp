/*
    author:Karan
    created:19.02.2023 16:55:19
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

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n), b(n);
    vector<ll> pos(n);
    set<ll> mini;
    for(ll i = 0; i< n;i++) {
        cin>>arr[i];
        arr[i]--;
        pos[arr[i]] = i;
        mini.insert(i);
    }
    for(ll i=0;i<n;i++) {
        cin>>b[i];
        b[i]--;
    }
    ll count = 0;
    for(ll i=0;i<n;i++) {
        if(*mini.begin() < pos[b[i]]) {
            count++;
        }
        mini.erase(pos[b[i]]);
    }
    cout<<min(count, n-count)<<endl;
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