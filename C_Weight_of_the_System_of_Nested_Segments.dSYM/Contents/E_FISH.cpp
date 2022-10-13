/*
    author:Karan
    created:06.11.2021 11:02:45
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

ld dp[1<<21];
ll n;
ld arr[20+1][20+1];

ld solv(ll prevbitmask,ll j) {
    ll k=__builtin_popcount(prevbitmask);
    ll den=(k*(k-1))/2;
    ld moveprob=0;
    for(ll i=0;i<n;i++) {
        if((1<<i)&prevbitmask) {
            moveprob+=arr[i][j];
        }
    }
    return (ld)moveprob/(den);
}

ld sol(ll bitmask) {
    ll alive=__builtin_popcount(bitmask);
    if(alive==n) {
        return 1;
    }
    if(dp[bitmask] > (-0.8)) {
        return dp[bitmask];
    }

    ld ans=0;
    for(ll i=0;i<n;i++) {
        if(!(bitmask&(1<<i))) {
            ld prevday= sol(bitmask^(1<<i));
            ans+=prevday*solv(bitmask^(1<<i),i);
        }
    }
    return dp[bitmask]=ans;
}


void solve() {
    cin>>n;    
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    mset(dp,-1);
    cout<<fixed;
    cout<<setprecision(6);
    for(ll i=0;i<n;i++) {
        cout<<sol(1<<i)<<" ";
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