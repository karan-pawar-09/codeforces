/*
    author:Karan
    created:15.10.2022 22:38:52
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
    cin>>n;
    vector<ll> arr(n);
    map<ll, ll> M;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        M[arr[i]]++;
    }
    vector<pair<ll, ll>> ar;
    for(auto x: M) {
        ar.push_back(x);
    }
    vector<ll> ans(n, 0);
    ll com = 0;
    for(ll i=ar.size()-1;i>=0;i--) {
        ans[com] += ar[i].second;
        com++;
    }
    for(auto x: ans) {
        cout<<x<<endl;
    }

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