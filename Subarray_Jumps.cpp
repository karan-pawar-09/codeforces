/*
    author:Karan
    created:27.11.2021 21:08:09
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

const ll inf=1e18+7;

void solve() {
    ll n;
    cin>>n;
    vector<ll> ar(n);
    for(ll i=0;i<n;i++) {
        cin>>ar[i];
    }
    ll temp=0;
    ll res=2*ar[0]-ar[n-1];
    for(ll i=1;i<n-1;i++) {
        if(ar[temp]<ar[i]) {
            res+=ar[temp];
        }
        else {
            res+=ar[i];
            temp=i;
        }
    }
    cout<<max(res,0LL)<<endl;
    
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