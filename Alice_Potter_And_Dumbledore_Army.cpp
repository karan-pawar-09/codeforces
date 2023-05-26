/*
    author:Karan
    created:08.02.2023 21:05:30
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

ll binarysearch(ll a,vector<ll> &arr,ll n) {
    ll l=-1;
    ll r=n-1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(arr[m]>=a) {
            r=m;
        }
        else {
            l=m;
        }
    }
    return r;
}

void solve() {
    ll n, m;
    cin>>n>>m;
    map<ll, vector<ll>> M;
    ll a, b;
    ll prevmax = 0;
    ll prevno = n+1;
    M[n+1].push_back(prevmax);
    for(ll i=0;i<m;i++) {
        cin>>a>>b;
        
        if(M[a].size()) {
            M[a][0] += b;
        } else {
            M[a].push_back(b);
        }
       
        
        prevmax += M[a][0];
        
        cout<<prevmax<<endl;
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