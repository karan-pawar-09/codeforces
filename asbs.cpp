/*
    author:Karan
    created:26.07.2022 15:02:34
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

const ll mx = 1e5+10;
const ll mod = 1e9+7;
void solve() {
    ll dp1[mx];
    ll dp2[mx];
    dp1[0]=3;
    dp2[0]=2;
    dp1[1]=4;
    dp2[1]=3;
    for(ll i=2;i<mx;i++) {
        dp1[i]=dp1[i-1]+(dp2[i-2]*3);
        dp2[i]=dp2[i-1]*2 + dp1[i-2];
        dp1[i]%=mod;
        dp2[i]%=mod;
        cout<<dp1[i]<<" "<<dp2[i]<<endl;
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