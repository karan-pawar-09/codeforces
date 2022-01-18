/*
    author:Karan
    created:10.01.2022 20:30:52
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
    sort(all(arr));
    bool ans=true;
    vector<bool> dp(n+1,false);
    for(int i=0;i<n;i++) {
        while(arr[i]>n) arr[i]/=2;    
        while(dp[arr[i]] and arr[i]>0) {
            arr[i]/=2;
        }            
        if(arr[i]<1) ans=false;
        else dp[arr[i]]=true;
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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