/*
    author:Karan
    created:16.02.2022 16:19:36
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

ll ceil(ll a,ll b) {
    return (a+b-1)/b;
}
void solve() {
    ll n,x,y;
    cin>>n>>x>>y;
    const ll inf=1e18+7;
    ll res=inf;
    for(ll i=0;i<=n;i++) {
        ll bus=n-i;
        ll car=i;
        res=min(res,ceil(bus,100)*x + ceil(car,4)*y);
    }
    cout<<res<<endl;
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