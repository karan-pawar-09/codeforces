/*
    author:Karan
    created:13.11.2021 17:44:37
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
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    unordered_map<ll,ll> M;
    unordered_map<ll,bool> A;
    for(ll i=0;i<n;i++) {
        M[arr[i]]++;
    }
    for(auto x:arr) {
        A[x]=false;
    }
    ll ans=0;
    for(ll i=1;i<=1000;i++) {
        for(ll j=1;j<=1000;j++) {
            ll area=(4*i*j)+(3*i)+(3*j);
            ll k=0;
            if(M.find(area)!=M.end()) {
                if(!A[area]) {
                    ans+=M[area];
                    A[area]=true;
                }
            }
        }
    }
    cout<<n-ans<<endl;
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