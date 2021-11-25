/*
    author:Karan
    created:23.11.2021 21:01:40
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

bool is_good (ll m,vector<pair<ll,ll>> &arr) {
    ll n=arr.size();
    ll taken=0;
    for(ll i=0;i<n;i++) {
        if(taken <= arr[i].second and (m-1-taken) <= arr[i].first) {
            taken++;
        }
    }
    if(taken>=m) return true;
    else return false;
}

void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }   

    ll l=0;
    ll r=n+1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(is_good(m,arr)) {
            l=m;
        } else {
            r=m;
        }
    }
    cout<<l<<endl;
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