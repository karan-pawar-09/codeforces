/*
    author:Karan
    created:05.02.2022 17:45:57
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

ll mod=998244353;
ll count(ll a) {
    if(a%2) {
        return ((a%mod)*(((a+1)/2)%mod))%mod;
    } else {
        return (((a/2)%mod)*((a+1)%mod))%mod;
    }
}
void solve() {
    ll n;
    cin>>n;
    ll prev=0;
    ll k=9;
    ll ans=0;
    while(k<n) {
        ans+=count(k-prev);
        ans%=mod;
        prev=k;
        k=10*(k+1);
        k--;
    }
    k=(k+1)/10;
    k--;
    ans+=count(n-k);
    ans%=mod;
    cout<<ans<<endl;
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