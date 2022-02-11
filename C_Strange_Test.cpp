/*
    author:Karan
    created:30.01.2022 20:51:34
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
    ll a,b;
    cin>>a>>b;
    ll xp=a;
    ll ans=b-a;
    while(xp<=b) {
        ll x=xp-a;
        for(ll y=0;y<=(b-a);y++) {
            ans=min(ans,x+y+1+((a+x)|(b+y))-(b+y));
        }
        xp=(xp|(xp-1))+1;
    }
    cout<<ans<<endl;
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