/*
    author:Karan
    created:15.01.2022 17:38:25
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
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    map<ll,vector<ll>> M;
    for(ll i=0;i<n;i++) {
        M[arr[i]].push_back(i+1);
    }
    ll a,b;
    for(ll i=0;i<q;i++) {
        cin>>a>>b;
        if(M[a].size()>=b) {
            cout<<M[a][b-1]<<endl;
        } else {
            cout<<-1<<endl;
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