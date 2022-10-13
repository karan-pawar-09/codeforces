/*
    author:Karan
    created:03.07.2022 12:15:50
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

ll n;
vector<int> arr;
ll dp[1<<22];
ll rec(ll x, ll y) {
    if(y==n) {
        return 0;
    } 
    if(dp[x]!=-1) {
        return dp[x];
    }
    ll res=1e9+10;
    for(ll i=0;i<n;i++) {
        if(!(x&(1<<i))) {
            ll temp = x^ (1<<i);
            res = min(res,rec(temp,y+1)+(arr[i]+y)/(y+1));
        }
    }
    dp[x]=res;
    return res;
}

void solve() {
    
    cin>>n;
    arr.resize(n);
    mset(dp,-1);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<rec(0,0)<<endl;

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